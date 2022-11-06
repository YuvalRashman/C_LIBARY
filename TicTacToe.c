//
// Created by Yuval Rashman on 11/6/2022.
//

#include <stdio.h>
#include "definesLib.h"

#define X_SIGN 'X'
#define O_SIGN 'O'
#define NONE_SIGN '-'
#define DIMENSION_SIZE 2
#define BOARD_LEN 3
#define TURNS_TO_SIGN_BOOL(turn)  IS_ODD(turns)
#define POS_IN_MASK(row, col) (row * BOARD_LEN + col)
#define POS_IN_MASK_TO_BITS(row, col) (ONE << POS_IN_MASK(row, col))
#define BOOL_TO_SIGN(bool) bool ? X_SIGN : O_SIGN

void printXorO(BOOL xOrO) {
    xOrO ? printf("%c", X_SIGN) : printf("%c", O_SIGN);
}

void printNone() {
    printf("%c",NONE_SIGN);
}

void printRow(unsigned short hasMask, unsigned short xOrOMask, unsigned short row) {
    unsigned short col;
    unsigned short posInBits;
    for (col = ZERO; col < BOARD_LEN; col++) {
        posInBits = POS_IN_MASK_TO_BITS(row, col);
        hasMask & posInBits ? printXorO((xOrOMask & posInBits) != ZERO) : printNone();
    }
    printf("\n");
}

void printBoard(unsigned short hasMask, unsigned short xOrOMask) {
    unsigned short row;
    for (row = ZERO; row < BOARD_LEN; row++) {
        printRow(hasMask, xOrOMask, row);
    }
}

BOOL isRowOrColSame(unsigned short hasMask, unsigned short xOrOMask, BOOL dimension, unsigned short pos) {
    unsigned short bitsToMove = BOARD_LEN * pos;
    unsigned short validateBits = dimension ? 7 : 0x49;
    return (((hasMask >> bitsToMove) & validateBits) == validateBits) * (!(((xOrOMask >> bitsToMove) & validateBits) %
                                                                           validateBits));
}

BOOL isDiagSame(unsigned short hasMask, unsigned short xOrOMask, BOOL mainOrSecond) {
    unsigned short diag = mainOrSecond ? 0x111 : 0x54;
    return (hasMask & diag) == diag * (!(((xOrOMask & diag) % diag)));
}

BOOL isWinner(unsigned short hasMask, unsigned short xOrOMask) {
    BOOL flag = isDiagSame(hasMask, xOrOMask, ONE) || isDiagSame(hasMask, xOrOMask, ZERO);
    unsigned short offset = 0;
    while (offset < 3 && !flag) {
        flag = isRowOrColSame(hasMask, xOrOMask, ZERO, offset) ||
               isRowOrColSame(hasMask, xOrOMask, ONE, offset++);
    }
    return flag;
}

void runTicTacToeGame() {
    unsigned short hasMask = ZERO;
    unsigned short xOrOMask = ZERO;
    unsigned short pos[DIMENSION_SIZE];
    BOOL win = ZERO;
    unsigned short turns = NINE;
    printBoard(hasMask, xOrOMask);
    while (!win && turns) {
        printf("enter row:\n");
        scanf("%hd", &pos[ZERO]);
        printf("enter col:\n");
        scanf("%hd", &pos[ONE]);
        printf("enter %c or %c:\n", X_SIGN, O_SIGN);
        hasMask |= POS_IN_MASK_TO_BITS(pos[ZERO], pos[ONE]);
        xOrOMask |= (TURNS_TO_SIGN_BOOL(turns)) << POS_IN_MASK(pos[ZERO], pos[ONE]);
        win = isWinner(hasMask, xOrOMask);
        printBoard(hasMask, xOrOMask);
        turns--;
    }
    if(turns) {
        printf("%c won!!!", BOOL_TO_SIGN(turns));
    } else{
        printf("tie");
    }
}

void main() {
    runTicTacToeGame();
}