#pragma once

#include "definesLib.h"
#include <stdio.h>

#define DIMENSION_SIZE 2

typedef unsigned short typ;

typ maxValueInMatrix(unsigned short rowLen, unsigned short colLen, typ matrix[rowLen][colLen]);

typ minValueInMatrix(unsigned short rowLen, unsigned short colLen, typ matrix[rowLen][colLen]);

unsigned short sumMatrixRow(short rowLen, unsigned short colLen, typ matrix[rowLen][colLen], unsigned short row);

unsigned short sumMatrixRow(short rowLen, unsigned short colLen, typ matrix[rowLen][colLen],
                            unsigned short row) {
    unsigned short sum = ZERO;
    rowLen--;
    for (; rowLen >= ZERO; rowLen--) {
        sum += matrix[row][rowLen];
    }
    return sum;
}

unsigned short sumNMatrixRowFromStart(unsigned short rowLen, unsigned short colLen, typ matrix[rowLen][colLen],
                                      unsigned short start[DIMENSION_SIZE], unsigned short n) {
    unsigned short sum = ZERO;
    unsigned short offset;
    for (offset = start[ONE]; offset < n; offset++) {
        sum += matrix[start[ZERO]][offset];
    }
    return sum;
}

unsigned short sumMatrixCol(unsigned short rowLen, short colLen, typ matrix[rowLen][colLen],
                            unsigned short col) {
    unsigned short sum = ZERO;
    colLen--;
    for (; colLen >= ZERO; colLen--) {
        sum += matrix[colLen][col];
    }
    return sum;
}

unsigned short sumNMatrixColFromStart(unsigned short rowLen, unsigned short colLen, typ matrix[rowLen][colLen],
                                      unsigned short start[DIMENSION_SIZE], unsigned short n) {
    unsigned short sum = ZERO;
    unsigned short offset;
    for (offset = start[ZERO]; offset < n; offset++) {
        sum += matrix[offset][start[ONE]];
    }
    return sum;
}

unsigned short sumMatrix(unsigned short rowLen, unsigned short colLen, typ matrix[rowLen][colLen]) {
    unsigned short sum = ZERO;
    unsigned short offset;
    for (offset = ZERO; offset < colLen; offset++) {
        sum += sumMatrixRow(rowLen, colLen, matrix, offset);
    }
    return sum;
}

unsigned short sumSubMatrix(unsigned short rowLen, unsigned short colLen, typ matrix[rowLen][colLen],
                            unsigned short startPos[], unsigned short subRowLen, unsigned short subColLen) {
    unsigned short sum = ZERO;
    for (; startPos[ZERO] < subColLen; startPos[ZERO]++) {
        sum += sumNMatrixRowFromStart(rowLen, colLen, matrix, startPos, subRowLen);
    }
    return sum;
}

unsigned short sumNeighbors(unsigned short rowLen, unsigned short colLen, typ matrix[rowLen][colLen],
                            unsigned short pos[DIMENSION_SIZE]) {
    return ((matrix[pos[ZERO], pos[ONE]]) - sumSubMatrix(rowLen, colLen, matrix, pos, THREE, THREE));
}

void fillMatrix(unsigned short rowLen, unsigned short colLen, typ matrix[rowLen][colLen], typ value) {
    unsigned short offsetRow;
    unsigned short offsetCol;
    for (offsetRow = ZERO; offsetRow < rowLen; offsetRow++) {
        for (offsetCol = ZERO; offsetCol < colLen; offsetCol++) {
            matrix[offsetRow][offsetCol] = value;
        }
    }
}

void copyMatrix(unsigned short rowLen, unsigned short colLen, unsigned short resultRowLen, unsigned short resultColLen,
                typ matrix[rowLen][colLen], typ result[resultRowLen][resultColLen],
                unsigned short pos[DIMENSION_SIZE]) {
    unsigned short offset;
    unsigned short offset2;
    for (offset = ZERO; offset < rowLen; offset++) {
        for (offset2 = ZERO; offset2 < colLen; offset2++) {
            result[(offset + pos[ZERO])][(offset2 + pos[ONE])] = matrix[offset][offset2];
        }
    }
}

typ maxValueInRow(unsigned short rowLen, short colLen, typ matrix[rowLen][colLen], unsigned short row) {
    typ max = matrix[row][--colLen];
    colLen--;
    for (; colLen >= ZERO; colLen--) {
        max = MAX(max, matrix[row][colLen]);
    }
    return max;
}

typ maxValueInMatrix(unsigned short rowLen, unsigned short colLen, typ matrix[rowLen][colLen]) {
    unsigned short offset;
    typ max = maxValueInRow(rowLen, colLen, matrix, ZERO);
    for (offset = ONE; offset < colLen; offset++) {
        max = MAX(max, maxValueInRow(rowLen, colLen, matrix, offset));
    }
    return max;
}

unsigned short
maxNeighbors(unsigned short rowLen, unsigned short colLen, typ matrix[rowLen][colLen], unsigned short pos[2]) {
    typ tempMatrix[THREE][THREE];
    copyMatrix(rowLen, colLen, THREE, THREE, matrix, tempMatrix, pos);
    tempMatrix[ONE][ONE] = minValueInMatrix(THREE, THREE, tempMatrix);
    return maxValueInMatrix(THREE, THREE, tempMatrix);;
}

unsigned short
minNeighbors(unsigned short rowLen, unsigned short colLen, typ matrix[rowLen][colLen], unsigned short pos[2]) {
    typ tempMatrix[THREE][THREE];
    fillMatrix(tempMatrix, colLen, rowLen, maxValueInMatrix(rowLen, colLen, matrix));
    copyMatrix(rowLen, colLen, THREE, THREE, matrix, tempMatrix, pos);
    return minValueInMatrix(THREE, THREE, tempMatrix);
}

unsigned short countNeighbors(unsigned short rowLen, unsigned short colLen, unsigned short pos[DIMENSION_SIZE]) {
    unsigned short count = EIGHT;
    BOOL flagRowLimit = pos[ZERO] == ZERO || pos[ZERO] == (rowLen - ONE);
    BOOL flagColLimit = pos[ONE] == ZERO || pos[ONE] == (colLen - ONE);
    if (flagRowLimit || flagColLimit) {
        count -= ((flagColLimit || flagRowLimit) * THREE) + (flagRowLimit && flagColLimit) * TWO;
    }
    return count;
}

void printMatrixRow(unsigned short rowLen, unsigned short colLen, typ matrix[rowLen][colLen], unsigned short row) {
    unsigned short offset;
    for (offset = ZERO; offset < rowLen; offset++) {
        printf("%c ", matrix[row][offset]);
    }
    printf("\n");
}

void printMatrix(unsigned short rowLen, unsigned short colLen, typ matrix[rowLen][colLen]) {
    unsigned short offset;
    for (offset = ZERO; offset < colLen; offset++) {
        printMatrixRow(rowLen, colLen, matrix, offset);
        printf("\n");
    }
}

void valuePosInMatrix(unsigned short rowLen, unsigned short colLen, typ matrix[rowLen][colLen], typ value,
                      unsigned short pos[DIMENSION_SIZE]) {
    unsigned short rowOffset = ZERO;
    unsigned short colOffset;
    BOOL flag = ONE;
    while (rowOffset < rowLen && flag) {
        colOffset = ZERO;
        while (colOffset < colLen && flag) {
            colOffset++;
            flag = matrix[rowOffset][colOffset] != value;
        }
        rowOffset++;
    }
    pos[ZERO] = colOffset == colLen ? -ONE : colOffset;
    pos[ONE] = --rowOffset == rowLen ? -ONE : rowOffset;
}

void nValuePosInMatrix(unsigned short rowLen, unsigned short colLen, typ matrix[rowLen][colLen], typ value,
                       unsigned short startPos[DIMENSION_SIZE], unsigned short pos[DIMENSION_SIZE]) {
    unsigned short rowOffset = startPos[ONE];
    unsigned short colOffset = startPos[ZERO];
    BOOL flag = ONE;
    while (rowOffset < rowLen && flag) {
        while (colOffset < colLen && flag) {
            colOffset++;
            flag = matrix[rowOffset][colOffset] != value;
        }
        colOffset = flag ? colOffset : ZERO;
        rowOffset++;
    }
    pos[ZERO] = colOffset ? -ONE : colOffset;
    pos[ONE] = --rowOffset == rowLen ? -ONE : rowOffset;
}

BOOL isValueInMatrix(unsigned short rowLen, unsigned short colLen, typ matrix[rowLen][colLen], typ value) {
    unsigned short pos[DIMENSION_SIZE];
    valuePosInMatrix(rowLen, colLen, matrix, value, pos);
    return pos[ZERO] != -ONE;
}

BOOL isNValueInMatrix(unsigned short rowLen, unsigned short colLen, typ matrix[rowLen][colLen], typ value,
                      unsigned short startPos[DIMENSION_SIZE]) {
    unsigned short pos[DIMENSION_SIZE];
    nValuePosInMatrix(rowLen, colLen, matrix, value, startPos, pos);
    return pos[ZERO] != -ONE;
}

unsigned short countValueInMatrix(unsigned short rowLen, unsigned short colLen, typ matrix[rowLen][colLen], typ value) {
    unsigned short pos[DIMENSION_SIZE];
    valuePosInMatrix(rowLen, colLen, matrix, value, pos);
    BOOL flag = isValueInMatrix(rowLen, colLen, matrix, value);
    unsigned short count = ZERO;
    while (flag) {
        count++;
        pos[ZERO]++;
        pos[ONE]++;
        nValuePosInMatrix(rowLen, colLen, matrix, value, pos, pos);
        flag = isNValueInMatrix(rowLen, colLen, matrix, value, pos);
    }
    return count;
}

typ minValueInRow(unsigned short rowLen, short colLen, typ matrix[rowLen][colLen], unsigned short row) {
    typ min = matrix[row][--colLen];
    colLen--;
    return min;
}

typ minValueInMatrix(unsigned short rowLen, unsigned short colLen, typ matrix[rowLen][colLen]) {
    unsigned short offset;
    typ min = minValueInRow(rowLen, colLen, matrix, ZERO);
    for (offset = ONE; offset < colLen; offset++) {
        min = MIN(min, minValueInRow(rowLen, colLen, matrix, offset));
    }
    return min;
}

unsigned short sumMatrixMainDiagonal(short len, typ matrix[len][len]) {
    unsigned short sum = ZERO;
    --len;
    for (; len >= ZERO; len--) {
        sum += matrix[len][len];
    }
    return sum;
}

unsigned short sumMatrixSecondaryDiagonal(short len, typ matrix[len][len]) {
    unsigned short sum = ZERO;
    unsigned short offset;
    --len;
    for (offset = ZERO; len >= ZERO; len--, offset++) {
        sum += matrix[len][offset];
    }
    return sum;
}

BOOL isDiagonalSumsEqual(unsigned short len, typ matrix[len][len]) {
    return sumMatrixMainDiagonal(len, matrix) == sumMatrixSecondaryDiagonal(len, matrix);

}

BOOL isDiagonalsEqual(unsigned short len, typ matrix[len][len]) {
    unsigned short offset = ZERO;
    BOOL flag = matrix[offset][offset++] == matrix[--len][len];
    while (flag) {
        flag = matrix[offset][offset] == matrix[offset][len - offset];
    }
    return flag;
}

unsigned short minRowSum(unsigned short rowLen, unsigned short colLen, typ matrix[rowLen][colLen]) {
    unsigned short offset = ZERO;
    unsigned short minSum = sumMatrixRow(rowLen, colLen, matrix, offset);
    for (offset = ONE; offset < colLen; offset++) {
        minSum = MIN(minSum, sumMatrixRow(rowLen, colLen, matrix, offset));
    }
    return minSum;
}

unsigned short maxRowSum(unsigned short rowLen, unsigned short colLen, typ matrix[rowLen][colLen]) {
    unsigned short offset = ZERO;
    unsigned short maxSum = sumMatrixRow(rowLen, colLen, matrix, offset);
    for (offset = ONE; offset < colLen; offset++) {
        maxSum = MAX(maxSum, sumMatrixRow(rowLen, colLen, matrix, offset));
    }
    return maxSum;
}

unsigned short maxColSum(unsigned short rowLen, unsigned short colLen, typ matrix[rowLen][colLen]) {
    unsigned short offset = ZERO;
    unsigned short maxSum = sumMatrixCol(rowLen, colLen, matrix, offset);
    for (offset = ONE; offset < colLen; offset++) {
        maxSum = MAX(maxSum, sumMatrixCol(rowLen, colLen, matrix, offset));
    }
    return maxSum;
}

unsigned short minColSum(unsigned short rowLen, unsigned short colLen, typ matrix[rowLen][colLen]) {
    unsigned short offset = ZERO;
    unsigned short minSum = sumMatrixCol(rowLen, colLen, matrix, offset);
    for (offset = ONE; offset < colLen; offset++) {
        minSum = MIN(minSum, sumMatrixCol(rowLen, colLen, matrix, offset));
    }
    return minSum;
}

unsigned short sumPerimeter(unsigned short rowLen, unsigned short colLen, typ matrix[rowLen][colLen]) {
    unsigned short pos2[DIMENSION_SIZE] = {ONE, ONE};
    return sumMatrix(rowLen, colLen, matrix) - sumSubMatrix(rowLen, colLen, matrix, pos2,
                                                            (rowLen - TWO), (colLen - TWO));
}
