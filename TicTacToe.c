//
// Created by yrash on 11/6/2022.
//

#pragma warning(disable:4996)

#include <stdio.h>
#include "definesLib.h"

#define boolToSign(sign) sign ? 'X' : 'O'

unsigned short markPos(unsigned short* hasMask, unsigned short* xOrOMask, unsigned short pos[2]) {
    *hasMask |= (1 << (pos[0] * 3 + pos[1]));
    *xOrOMask |= (1 << (pos[0] * 3 + pos[1]));
}

void printXorO(BOOL xOrO) { // always 1
    xOrO ? printf("X ") : printf(" O");
}

void printNone() {
    printf("-");
}

void printRow(unsigned short hasMask, unsigned short xOrOMask, unsigned short row) {
    unsigned short colume;
    unsigned short pos;
    for (colume = 0; colume < 3; colume++) {
        pos = (1 << (row * 3 + colume));
        hasMask& pos ? printXorO((xOrOMask & pos)) : printNone();
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
    unsigned short pos[2];
    unsigned short row;
    unsigned short col;
    unsigned short temp;
    BOOL win = 0;
    BOOL sign;
    printBoard(hasMask, xOrOMask);
    while (!win) {
        printf("enter row:");
        scanf("%d", &row);
        printf("enter col:");
        scanf("%d", &col);
        pos[0] = row;
        pos[1] = col;
        printf("enter x or o (1 or 0)");
        scanf("%d", &sign);
        hasMask |= 1 << (pos[0] * 3 + pos[1]);
        xOrOMask |= (sign << (pos[0] * 3 + pos[1]));
        win = isWinner(hasMask, xOrOMask);
        printBoard(hasMask, xOrOMask);
    }
    printf("%c won!!!", boolToSign(sign));
}

void main() {
    runGame();
}