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



void initBoard(char matrix[THREE][THREE]) {
    fillMatrix(THREE, THREE, matrix, '-');
}

void printBoard(char matrix[THREE][THREE]) {
    printMatrix(THREE, THREE, matrix);
}

//1 is for X and 0 is for O
void markPos(char matrix[THREE][THREE], BOOL xOrC, unsigned short pos[2]) {
    matrix[pos[0]][pos[1]] = xOrC ? 'X' : 'O';
}

BOOL isThereThreeInColOrRow(char matrix[3][3], char value, BOOL dimension){
    unsigned short offset = 0;
    unsigned short sum;
    BOOL flag = 0;
    while (offset < 3 && !flag) {
        sum = dimension ? sumMatrixRow(3, 3, matrix, offset++) :
                sumMatrixCol(3, 3, matrix, offset++);
        flag = sum / value == 3 && !(sum % value);
    }
    return flag;
}

BOOL isThereThreeInDiag(char matrix[3][3], char value, BOOL mainOrSec){
    unsigned short sum;
    BOOL flag = 0;
    sum = mainOrSec ? sumMatrixMainDiagonal(3, matrix) : sumMatrixSecondaryDiagonal(3, matrix);
    flag = (((sum / value) == 3) && (!(sum % value)));
    return flag;
}

// return winner if there is or EOD if there isn't
BOOL isWinner(char matrix[THREE][THREE]) {
    unsigned short offset;
    BOOL flag = 0;
    flag = isThereThreeInDiag(matrix, 'X', 1) || isThereThreeInDiag(matrix, 'X', 0) ||
            isThereThreeInDiag(matrix, 'O', 1) || isThereThreeInDiag(matrix, 'O', 0);
    for (offset = 0; offset < THREE && !flag; offset++) {
        flag = isThereThreeInColOrRow(matrix, 'X', 1) || isThereThreeInColOrRow(matrix, 'X', 0) ||
                isThereThreeInColOrRow(matrix, 'O', 1) || isThereThreeInColOrRow(matrix, 'O', 0);
    }
    return flag;
}

void runGameXmitrix(){
    printf("X is %d\n", 'X');
    printf("O is %d\n", 'O');
    printf(" - is %d\n", '-');
    char board[3][3];
    initBoard(board);
    BOOL flagIsWinner = 0;
    char sign;
    unsigned short pos[2];
    printBoard(board);
    unsigned short count = 0;
    while (!flagIsWinner && count < 9){
        printf("enter row: \n");
        scanf("%d", &pos[0]);
        printf("enter col: \n");
        scanf("%d", &pos[1]);
        printf("enter X or O \n");
        scanf(" %c", &sign);
        markPos(board, (sign == 'X' ? 1 : 0), pos);
        count++;
        flagIsWinner = isWinner(board);
        printBoard(board);
    }
    if(count < 9) {
        printf("the winner is: %c", sign);
    }
    else{
        printf("tie");
    }
}


void main() {
    runGameXmitrix();
}
