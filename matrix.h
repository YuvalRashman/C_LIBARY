#pragma once

#include "definesLib.h"
#include <stdio.h>

#define DIMENSION_SIZE 2

typedef unsigned short typ;

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
                                      unsigned short start[2], unsigned short n) {
    unsigned short sum = ZERO;
    unsigned short offset;
    for (offset = start[1]; offset < n; offset++) {
        sum += matrix[start[0]][offset];
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
                                      unsigned short start[2], unsigned short n) {
    unsigned short sum = ZERO;
    unsigned short offset;
    for (offset = start[0]; offset < n; offset++) {
        sum += matrix[offset][start[1]];
    }
    return sum;
}

unsigned short sumMatrix(unsigned short rowLen, unsigned short colLen, typ matrix[rowLen][colLen]) {
    unsigned short sum = 0;
    unsigned short offset;
    for (offset = 0; offset < colLen; offset++) {
        sum += sumMatrixRow(rowLen, colLen, matrix, offset);
    }
    return sum;
}

unsigned short sumSubMatrix(unsigned short rowLen, unsigned short colLen, typ matrix[rowLen][colLen],
                            unsigned short startPos[], unsigned short subRowLen, unsigned short subColLen) {
    unsigned short sum = 0;
    for (; startPos[0] < subColLen; startPos[0]++) {
        sum += sumNMatrixRowFromStart(rowLen, colLen, matrix, startPos, subRowLen);
    }
    return sum;
}

unsigned short sumNeighbors(unsigned short rowLen, unsigned short colLen, typ matrix[rowLen][colLen],
                            unsigned short pos[2]) {
    return ((matrix[pos[0], pos[1]]) - sumSubMatrix(rowLen, colLen, matrix, pos, 3, 3));
}

unsigned short maxNeighbors() {

}

unsigned short minNeighbors() {

}

unsigned short countNeighbors(unsigned short rowLen, unsigned short colLen, unsigned short pos[2]) {
    unsigned short count = 8;
    BOOL flagRowLimit = pos[0] == 0 || pos[0] == (rowLen - 1);
    BOOL flagColLimit = pos[1] == 0 || pos[1] == (colLen - 1);
    if (flagRowLimit || flagColLimit) {
        count -= ((flagColLimit || flagRowLimit) * 3) + (flagRowLimit && flagColLimit) * 2;
    }
    return count;
}

void printMatrixRow(unsigned short rowLen, unsigned short colLen, typ matrix[rowLen][colLen], unsigned short row) {
    unsigned short offset;
    for (offset = 0; offset < rowLen; offset++) {
        printf("%d ", matrix[row][offset]);
    }
    printf("\n");
}

void printMatrix(unsigned short rowLen, unsigned short colLen, typ matrix[rowLen][colLen]) {
    unsigned short offset;
    for (offset = 0; offset < colLen; offset++) {
        printMatrixRow(rowLen, colLen, matrix, offset);
        printf("\n");
    }
}

void valuePosInMatrix(unsigned short rowLen, unsigned short colLen, typ matrix[rowLen][colLen], typ value,
                      unsigned short pos[2]) {
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
                      unsigned short startPos[2]) {
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

typ maxValueInRow(unsigned short rowLen, short colLen, typ matrix[rowLen][colLen], unsigned short row) {
    typ max = matrix[row][--colLen];
    colLen--;
    for (; colLen >= ZERO; colLen--) {
        max = MAX(max, matrix[row][colLen]);
    }
    return max;
}

typ minValueInRow(unsigned short rowLen, short colLen, typ matrix[rowLen][colLen], unsigned short row) {
    typ min = matrix[row][--colLen];
    colLen--;
    for (; colLen >= ZERO; colLen--) {
        min = MIN(min, matrix[row][colLen]);
    }
    return min;
}

typ maxValueInCol(short rowLen, unsigned short colLen, typ matrix[rowLen][colLen], unsigned short col) {
    typ max = matrix[--rowLen][col];
    rowLen--;
    for (; rowLen >= ZERO; rowLen--) {
        max = MAX(max, matrix[rowLen][col]);
    }
    return max;
}

typ minValueInCol(short rowLen, unsigned short colLen, typ matrix[rowLen][colLen], unsigned short col) {
    typ min = matrix[--rowLen][col];
    rowLen--;
    for (; rowLen >= ZERO; rowLen--) {
        min = MIN(min, matrix[rowLen][col]);
    }
    return min;
}

typ maxValueInMatrix(unsigned short rowLen, unsigned short colLen, typ matrix[rowLen][colLen]) {
    unsigned short offset;
    typ max = maxValueInRow(rowLen, colLen, matrix, 0);
    for (offset = 1; offset < colLen; offset++) {
        max = MAX(max, maxValueInRow(rowLen, colLen, matrix, offset));
    }
    return max;
}

typ minValueInMatrix(unsigned short rowLen, unsigned short colLen, typ matrix[rowLen][colLen]) {
    unsigned short offset;
    typ min = minValueInRow(rowLen, colLen, matrix, 0);
    for (offset = 1; offset < colLen; offset++) {
        min = MIN(min, maxValueInRow(rowLen, colLen, matrix, offset));
    }
    return min;
}

unsigned short sumMatrixMainDiagonal(short len, typ matrix[len][len]) {
    unsigned short sum = 0;
    --len;
    for (; len >= 0; len--) {
        sum += matrix[len][len];
    }
    return sum;
}

unsigned short sumMatrixSecondaryDiagonal(short len, typ matrix[len][len]) {
    unsigned short sum = 0;
    unsigned short offset;
    --len;
    for (offset = 0; len >= 0; len--, offset++) {
        sum += matrix[len][offset];
    }
    return sum;
}

BOOL isDiagonalSumsEqual(unsigned short len, typ matrix[len][len]) {
    return sumMatrixMainDiagonal(len, matrix) == sumMatrixSecondaryDiagonal(len, matrix);

}

BOOL isDiagonalsEqual(unsigned short len, typ matrix[len][len]) {
    unsigned short offset = 0;
    BOOL flag = matrix[offset][offset++] == matrix[--len][len];
    while (flag) {
        flag = matrix[offset][offset] == matrix[offset][len - offset];
    }
    return flag;
}

unsigned short minRowSum(unsigned short rowLen, unsigned short colLen, typ matrix[rowLen][colLen]) {
    unsigned short offset = 0;
    unsigned short minSum = sumMatrixRow(rowLen, colLen, matrix, offset);
    for (offset = 1; offset < colLen; offset++) {
        minSum = MIN(minSum, sumMatrixRow(rowLen, colLen, matrix, offset));
    }
    return minSum;
}

unsigned short maxRowSum(unsigned short rowLen, unsigned short colLen, typ matrix[rowLen][colLen]) {
    unsigned short offset = 0;
    unsigned short maxSum = sumMatrixRow(rowLen, colLen, matrix, offset);
    for (offset = 1; offset < colLen; offset++) {
        maxSum = MAX(maxSum, sumMatrixRow(rowLen, colLen, matrix, offset));
    }
    return maxSum;
}

unsigned short maxColSum(unsigned short rowLen, unsigned short colLen, typ matrix[rowLen][colLen]) {
    unsigned short offset = 0;
    unsigned short maxSum = sumMatrixCol(rowLen, colLen, matrix, offset);
    for (offset = 1; offset < colLen; offset++) {
        maxSum = MAX(maxSum, sumMatrixCol(rowLen, colLen, matrix, offset));
    }
    return maxSum;
}

unsigned short minColSum(unsigned short rowLen, unsigned short colLen, typ matrix[rowLen][colLen]) {
    unsigned short offset = 0;
    unsigned short minSum = sumMatrixCol(rowLen, colLen, matrix, offset);
    for (offset = 1; offset < colLen; offset++) {
        minSum = MIN(minSum, sumMatrixCol(rowLen, colLen, matrix, offset));
    }
    return minSum;
}

unsigned short sumPerimeter(unsigned short rowLen, unsigned short colLen, typ matrix[rowLen][colLen]) {
    unsigned short pos2[2] = {1, 1};
    return sumMatrix(rowLen, colLen, matrix) - sumSubMatrix(rowLen, colLen, matrix,
                                                            pos2, (rowLen - 2), (colLen - 2));
}

void copyMatrix(unsigned short rowLen, unsigned short colLen, unsigned short resultRowLen, unsigned short resultColLen,
                typ matrix[rowLen][colLen], typ result[resultRowLen][resultColLen],
                unsigned short pos[2]) {
    unsigned short offset;
    unsigned short offset2;
    for (offset = 0; offset < rowLen; offset++) {
        for (offset2 = 0; offset2 < colLen; offset2++) {
            result[(offset + pos[0])][(offset2 + pos[1])] = matrix[offset][offset2];
        }
    }
}
