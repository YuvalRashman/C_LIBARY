//
// Created by yrash on 11/12/2022.
//

#include "definesLib.h"
#include <math.h>

void replaceNumbers(unsigned short *num1, unsigned short *num2) {
    *num1 ^= *num2;
    *num2 ^= *num1;
    *num1 ^= *num2;
}

void sumTwoNumbers(unsigned short *num1, unsigned short *num2, unsigned short *result) {
    *result = *num1 + *num2;
}

void sumDigits(unsigned short num, unsigned short *result) {
    *result = ZERO;
    while (num) {
        *result += num % TEN;
        num /= TEN;
    }
}

void sumEvenDigits(unsigned short num, unsigned short *result) {
    *result = ZERO;
    unsigned short digit;
    while (num) {
        digit = num % TEN;
        *result += IS_EVEN(digit) * digit;
        num /= TEN;
    }
}

void sumOddDigits(unsigned short num, unsigned short *result) {
    unsigned short temp = ZERO;
    sumDigits(num, *result);
    sumEvenDigits(num, &temp);
    *result -= temp;
}

void isDigitInNumber(unsigned short num, unsigned short digit, BOOL *result) {
    *result = FALSE;
    while (num && !(*result)) {
        *result = num % TEN == digit;
        num /= TEN;
    }
}

void countDigits(unsigned short num, unsigned short *count) {
    *count = ZERO;
    while (num) {
        *count++;
        num /= TEN;
    }
}

void combineTwoNumbers(unsigned short num1, unsigned short num2, unsigned short *result) {
    *result = ZERO;
    countDigits(num2, result);
    *result = num1 * pow(TEN, *result) + num2;
}

void witchDigitsInNumebr(unsigned short num, unsigned short *mask){
    *mask = 0;
    while (num){
        *mask &= ONE << num % TEN;
        num /= TEN;
    }
}

void isNumbersShareDigits(unsigned short num1, unsigned short num2, BOOL *result) {
    unsigned short mask1;
    unsigned short mask2;
    witchDigitsInNumebr(num1, &mask1);
    witchDigitsInNumebr(num2, &mask2);
    *result = (mask1 & mask2) != ZERO;
}

