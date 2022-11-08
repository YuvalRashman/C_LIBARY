#include <stdio.h>
#include "stringL.h"
#include "matrix.h"

#define THREE 3

BOOL isMagicSquare(unsigned short len, short matrix[len][len]) {
    BOOL flag = 1;
    unsigned short offset = 0;
    unsigned short currentSize = sumMatrixMainDiagonal(len, matrix);
    flag = (currentSize == sumMatrixSecondaryDiagonal(len, matrix));
    while (offset < len && flag) {
        flag = ((currentSize == sumMatrixCol(len, len, matrix, offset)) &&
                (currentSize == sumMatrixRow(len, len, matrix, offset++)));
    }
    return flag;
}

void main() {
    unsigned short arr[3][3] = {{8,1,6}, {3,5,7}, {4,9,2}};
    printf("%d", isMagicSquare(3, arr));
}
