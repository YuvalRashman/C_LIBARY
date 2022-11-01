#pragma once

#include "definesLib.h"
#include <stdio.h>

#define DIMENSION_SIZE 2
#define ROW_SIZE 10

typedef unsigned short typ;

unsigned short sumMatrixRow(typ matrix[][ROW_SIZE], unsigned short row, unsigned short len) {
    unsigned short sum = ZERO;
    len--;
    for (; len > ZERO; len--) {
        sum += matrix[len][row];
    }
    return sum;
}

unsigned short sumMatrixCol(typ matrix[][ROW_SIZE], unsigned short col, unsigned short len) {
    unsigned short sum = ZERO;
    len--;
    for (; len > ZERO; len--) {
        sum += matrix[col][len];
    }
    return sum;
}

unsigned short sumMatrix(typ matrix[][ROW_SIZE], unsigned short rowLen, unsigned short colLen) {
    unsigned short sum = ZERO;
    colLen--;
    for (; colLen > ZERO; colLen--) {
        sum += sumMatrixRow(matrix, colLen, rowLen);
    }
    return sum;
}

void printMatrixRow(typ matrix[][ROW_SIZE], unsigned short rowLen, unsigned short row) {
    unsigned short offset;
    for (offset = 0; offset < rowLen; offset++) {
        printf("%d ", matrix[offset][row]);
    }
    printf("\n");
}

void printMatrix(typ matrix[][ROW_SIZE], unsigned short rowLen, unsigned short colLen) {
    unsigned short offset;
    for (offset = 0; offset < colLen; offset++) {
        printMatrixRow(matrix, rowLen, offset);
    }
    printf("\n");
}

void valuePosInMatrix(typ matrix[][ROW_SIZE], unsigned short rowLen, unsigned short colLen, typ value,
                      unsigned short pos[2]) {
    unsigned short rowOffset = ZERO;
    unsigned short colOffset;
    BOOL flag = ONE;
    while (rowOffset < rowLen && flag) {
        colOffset = ZERO;
        while (colOffset < colLen && flag) {
            colOffset++;
            flag = matrix[colOffset][rowOffset] != value;
        }
        rowOffset++;
    }
    pos[ZERO] = colOffset == colLen ? -ONE : colOffset;
    pos[ONE] = --rowOffset == rowLen ? -ONE : rowOffset;
}

void nValuePosInMatrix(typ matrix[][ROW_SIZE], unsigned short rowLen, unsigned short colLen, typ value,
                       unsigned short startPos[DIMENSION_SIZE], unsigned short pos[DIMENSION_SIZE]) {
    unsigned short rowOffset = startPos[ONE];
    unsigned short colOffset = startPos[ZERO];
    BOOL flag = ONE;
    while (rowOffset < rowLen && flag) {
        while (colOffset < colLen && flag) {
            colOffset++;
            flag = matrix[colOffset][rowOffset] != value;
        }
        colOffset = flag ? colOffset : ZERO;
        rowOffset++;
    }
    pos[ZERO] = colOffset ? -ONE : colOffset;
    pos[ONE] = --rowOffset == rowLen ? -ONE : rowOffset;
}

BOOL isValueInMatrix(typ matrix[][ROW_SIZE], unsigned short rowLen, unsigned short colLen, typ value) {
    unsigned short pos[DIMENSION_SIZE];
    valuePosInMatrix(matrix, rowLen, colLen, value, pos);
    return pos[ZERO] != -ONE;
}

BOOL isNValueInMatrix(typ matrix[][ROW_SIZE], unsigned short rowLen, unsigned short colLen, typ value,
                      unsigned short startPos[2]) {
    unsigned short pos[DIMENSION_SIZE];
    nValuePosInMatrix(matrix, rowLen, colLen, value, startPos, pos);
    return pos[ZERO] != -ONE;
}

unsigned short countValueInMatrix(typ matrix[][ROW_SIZE], unsigned short rowLen, unsigned short colLen, typ value) {
    unsigned short pos[DIMENSION_SIZE];
    valuePosInMatrix(matrix, rowLen, colLen, value, pos);
    BOOL flag = isValueInMatrix(matrix, rowLen, colLen, value);
    unsigned short count = ZERO;
    while (flag) {
        count++;
        pos[ZERO]++;
        pos[ONE]++;
        nValuePosInMatrix(matrix, rowLen, colLen, value, pos, pos);
        flag = isNValueInMatrix(matrix, rowLen, colLen, value, pos);
    }
    return count;
}

typ maxValueInRow(typ matrix[][ROW_SIZE], unsigned short row, unsigned short len) {
    typ max = matrix[--len][row];
    len--;
    for (; len > ZERO; len--) {
        max = MAX(max, matrix[len][row]);
    }
    return max;
}

typ minValueInRow(typ matrix[][ROW_SIZE], unsigned short row, unsigned short len) {
    typ min = matrix[--len][row];
    len--;
    for (; len > ZERO; len--) {
        min = MIN(min, matrix[len][row]);
    }
    return min;
}

typ maxValueInCol(typ matrix[][ROW_SIZE], unsigned short col, unsigned short len) {
    typ max = matrix[col][--len];
    len--;
    for (; len > ZERO; len--) {
        max = MAX(max, matrix[col][len]);
    }
    return max;
}

typ minValueInCol(typ matrix[][ROW_SIZE], unsigned short col, unsigned short len) {
    typ min = matrix[col][--len];
    len--;
    for (; len > ZERO; len--) {
        min = MIN(min, matrix[col][len]);
    }
    return min;
}

typ maxValueInMatrix(typ matrix[][ROW_SIZE], unsigned short rowLen, unsigned short coulLen) {
    typ max = maxValueInRow(matrix, --coulLen, rowLen);
    coulLen--;
    for (; coulLen > ZERO; coulLen--) {
        max = MAX(max, maxValueInRow(matrix, coulLen, rowLen));
    }
    return max;
}

typ minValueInMatrix(typ matrix[][ROW_SIZE], unsigned short rowLen, unsigned short colLen) {
    typ min = minValueInRow(matrix, --colLen, rowLen);
    colLen--;
    for (; colLen > ZERO; colLen--) {
        min = MIN(min, minValueInRow(matrix, colLen, rowLen));
    }
    return min;
}

unsigned short sumMatrixMainDiagonal(typ matrix[][ROW_SIZE], unsigned short len) {
    unsigned short sum = 0;
    --len;
    for (; len >= 0; len--) {
        sum += matrix[len][len];
    }
    return sum;
}

unsigned short sumMatrixSecondaryDiagonal(typ matrix[][ROW_SIZE], unsigned short len) {
    unsigned short sum = 0;
    unsigned short offset;
    --len;
    for (offset = 0; len >= 0; len--, offset++) {
        sum += matrix[offset][len];
    }
    return sum;
}

BOOL isDiagonalSumsEqual(typ matrix[][ROW_SIZE], unsigned short len) {
    return sumMatrixMainDiagonal(matrix, len) == sumMatrixSecondaryDiagonal(matrix, len);

}

BOOL isDiagonalsEqual(typ matrix[][ROW_SIZE], unsigned short len) {
    unsigned short offset = 0;
    BOOL flag = matrix[offset][offset++] == matrix[--len][len];
    while (flag) {
        flag = matrix[offset][offset] == matrix[len - offset][offset];
    }
    return flag;
}


float matrixAverage(typ matrix[][ROW_SIZE], unsigned short rowLen, unsigned short colLen) {
    return sumMatrix(matrix, rowLen, colLen) / (colLen * rowLen);
}

