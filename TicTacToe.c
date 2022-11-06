//
// Created by yrash on 11/6/2022.
//

#include <stdio.h>
#include "definesLib.h"

#define SignToBool(sign) sign == 'X' ? 1 : 0

unsigned short markPos(unsigned short *hasMask, unsigned short *xOrOMask, unsigned short pos[2]) {
    *hasMask |= (1 << (pos[0] * 3 + pos[1]));
    *xOrOMask |= (1 << (pos[0] * 3 + pos[1]));
}

void printXorO(BOOL xOrO) { // always 1
    (xOrO > 0) ? printf("X ") : printf(" O");
}

void printNone() {
    printf("-");
}

void printRow(unsigned short hasMask, unsigned short xOrOMask, unsigned short row) {
    unsigned short colume;
    unsigned short pos;
    unsigned temp;
    for (colume = 0; colume < 3; colume++) {
        pos = (1 << (row * 3 + colume));
        hasMask & pos ? printXorO((xOrOMask & pos) != 0) : printNone();
    }
}

void printBoard(unsigned short hasMask, unsigned short xOrOMask) {
    unsigned short row;
    for (row = 0; row < 3; row++) {
        printRow(hasMask, xOrOMask, row);
        printf("\n");
    }
}

BOOL isRowOrColSame(unsigned short hasMask, unsigned short xOrOMask, BOOL dimension, unsigned short pos) {
    unsigned short realPose = 3 * pos;
    unsigned short num = dimension ? 7 : 0x49;
    return (((hasMask >> realPose) & num) == num) * (!(((xOrOMask >> realPose) & num) % num));
}

BOOL isDiagSame(unsigned short hasMask, unsigned short xOrOMask, BOOL mainOrSecond) {
    unsigned short diag = mainOrSecond ? 0x111 : 0x54;
    return (hasMask & diag) == diag * (!(((xOrOMask & diag) % diag)));
}

BOOL isWinner(unsigned short hasMask, unsigned short xOrOMask) {
    BOOL flag = isDiagSame(hasMask, xOrOMask, 1) || isDiagSame(hasMask, xOrOMask, 0);
    unsigned short offset = 0;
    while (offset < 3 && !flag) {
        flag = isRowOrColSame(hasMask, xOrOMask, 0, offset) ||
               isRowOrColSame(hasMask, xOrOMask, 1, offset++);
    }
    return flag;
}

void runGame() {
    unsigned short hasMask = 0;
    unsigned short xOrOMask = 0;
    unsigned short pos[2] = {0};
    BOOL win = 0;
    BOOL sign = 'X';
    printBoard(hasMask, xOrOMask);
    while (!win) {
        printf("enter row:");
        scanf("%d", &pos[0]);
        printf("enter col:");
        scanf("%d", &pos[1]);
        printf("enter x or o (1 or 0)\n");
        scanf(" %c", &sign);
        hasMask |= (1 << (pos[0] * 3 + pos[1]));
        xOrOMask |= ((SignToBool(sign)) << (pos[0] * 3 + pos[1]));
        win = isWinner(hasMask, xOrOMask);
        printBoard(hasMask, xOrOMask);
    }
    printf("%c won!!!", sign);
}

void main() {
    runGame();
}