#include <stdio.h>
/*#include "stringL.h"
#include "matrix.h"*/
#include "numbersLibary.h"

/*#define THREE 3
#define DIM_SIZE(len, value, colOrRow) (colOrRow ? value / len : value % len)

//Ex1
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



//Ex4
BOOL isFlowerArray(short matrix[3][3]) {
    return (sumMatrixSecondaryDiagonal(3, matrix) + sumMatrixMainDiagonal(3, matrix) - 2 * matrix[1][1]) ==
           matrix[1][1];
}

unsigned short countFlowers(unsigned short rowLen, unsigned short colLen, short matrix[rowLen][colLen]) {
    unsigned short counter = 0;
    unsigned short pos[2] = {0};
    unsigned short copyMat[3][3];
    colLen--;
    rowLen--;
    for (pos[0] = 1; pos[0] < colLen; pos[0]++) {
        for (pos[1] = 1; pos[1] < rowLen; pos[1]++) {
            copyMatrix(rowLen, colLen, 3, 3, matrix, copyMat, pos);
            counter += isFlowerArray(copyMat);
        }
    }
    return counter;
}

BOOL isFlowery(unsigned short rowLen, unsigned short colLen, short matrix[rowLen][colLen]) {
    return countFlowers(rowLen, colLen, matrix) >= 5;
}

//Ex5
unsigned short calculateSize(unsigned short rowLen, unsigned short start, unsigned short end) {
    return ((DIM_SIZE(rowLen, end, 0)) - (DIM_SIZE(rowLen, start, 0)) + 1) *
    ((DIM_SIZE(rowLen, end, 1)) - (DIM_SIZE(rowLen, start, 1)) + 1);

}

unsigned short subArea(unsigned short rowLen,
                       unsigned short firstStart, unsigned short firstEnd, unsigned short secondStart,
                       unsigned short secondEnd) {
    return MAX(calculateSize(rowLen, firstStart, firstEnd),
               calculateSize(rowLen, secondStart, secondEnd));
}


char* addressOfChar(char *str, char ch){
    char *temp = str;
    while ((*(temp)) * (*(temp++) == ch));
    return temp--;
}

BOOL exsist(char *str, char  ch){
    char *temp = addressOfChar(str, ch);
    return *temp != '\0';
}

unsigned short countChar(char *str, char ch){
    char *temp = addressOfChar(str, ch);
    unsigned short counter = 0;
    while (*temp){
        counter++;
        temp = addressOfChar(temp++, ch);
    }
    return counter;
}*/

void main() {
    int num1 = 16384, num2 = 7;
    int result;
    sqrtNumber(num1, num2, &result);
    printf("%d", result);
}
