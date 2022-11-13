//
// Created by yrash on 11/12/2022.
//

#include "definesLib.h"
#include <math.h>

#define IS_ODD_POINTERS(x) *x % TWO
#define IS_EVEN_POINTERS(x) !IS_ODD_POINTERS(x)


//--------------------------------------------------------------------------------------------------------------------
//                                                  replaceNumbers
//                                                  --------------
//
// General : The function replace two numbers.
//
// Parameters :
// num1 - pointer to first number (In)
// num2 - pointer to second number (In)
//
// Return Value : None.
//
//--------------------------------------------------------------------------------------------------------------------
void replaceNumbers(unsigned short *num1, unsigned short *num2) {
    *num1 ^= *num2;
    *num2 ^= *num1;
    *num1 ^= *num2;
}

//--------------------------------------------------------------------------------------------------------------------
//                                                  sumTwoNumbers
//                                                  -------------
//
// General : The function sum two numbers and save the result in pointer.
//
// Parameters :
// num1 - first number (In)
// num2 - second number (In)
// result - pointer to the parameter we are going to save the result (In)
//
// Return Value : None.
//
//--------------------------------------------------------------------------------------------------------------------
void sumTwoNumbers(unsigned short *num1, unsigned short *num2, unsigned short *result) {
    *result = *num1 + *num2;
}

//--------------------------------------------------------------------------------------------------------------------
//                                                    sumDigits
//                                                    ---------
//
// General : The function sum all the digits of a number and save the result in pointer.
//
// Parameters :
// num - the number (In)
// result - pointer to the parameter we are going to save the result (In)
//
// Return Value : None.
//
//--------------------------------------------------------------------------------------------------------------------
void sumDigits(unsigned short num, unsigned short *result) {
    *result = ZERO;
    while (num) {
        *result += num % TEN;
        num /= TEN;
    }
}

//--------------------------------------------------------------------------------------------------------------------
//                                                  sumEvenDigits
//                                                  -------------
//
// General : The function sum the even digits of a number and save the result in pointer.
//
// Parameters :
// num - the number (In)
// result - pointer to the parameter we are going to save the result (In)
//
// Return Value : None.
//
//--------------------------------------------------------------------------------------------------------------------
void sumEvenDigits(unsigned short num, unsigned short *result) {
    *result = ZERO;
    unsigned short digit;
    while (num) {
        digit = num % TEN;
        *result += IS_EVEN(digit) * digit;
        num /= TEN;
    }
}

//--------------------------------------------------------------------------------------------------------------------
//                                                  sumOddDigits
//                                                  -------------
//
// General : The function sum the odd digits of a number and save the result in pointer.
//
// Parameters :
// num - the number (In)
// result - pointer to the parameter we are going to save the result (In)
//
// Return Value : None.
//
//--------------------------------------------------------------------------------------------------------------------
void sumOddDigits(unsigned short num, unsigned short *result) {
    unsigned short temp = ZERO;
    sumDigits(num, *result);
    sumEvenDigits(num, &temp);
    *result -= temp;
}

//--------------------------------------------------------------------------------------------------------------------
//                                                  isDigitInNumber
//                                                  -------------
//
// General : The function check if digit is in number.
//
// Parameters :
// num - the number (In)
// digit - the digit (In)
// result -  pointer to the parameter we are going to save the result (In)
//
// Return Value : None.
//
//--------------------------------------------------------------------------------------------------------------------
void isDigitInNumber(unsigned short num, unsigned short digit, BOOL *result) {
    *result = FALSE;
    while (num && !(*result)) {
        *result = num % TEN == digit;
        num /= TEN;
    }
}

//--------------------------------------------------------------------------------------------------------------------
//                                                  countDigits
//                                                  -------------
//
// General : This function count the number of digits in number.
//
// Parameters :
// num - the number (In)
// count - pointer to the parameter we are going to save the result (In)
//
// Return Value : None.
//
//--------------------------------------------------------------------------------------------------------------------
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

void witchDigitsInNumebr(unsigned short num, unsigned short *mask) {
    *mask = 0;
    while (num) {
        *mask |= ONE << (num % TEN);
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

void newNumberFromEvenDigits(unsigned short num, unsigned short *result) {
    *result = 0;
    unsigned short digit;
    unsigned BOOL con;
    while (num) {
        digit = num % 10;
        con = IS_EVEN_POINTERS(&digit);
        *result = *result * pow(TEN, con) + con * digit;
        num /= TEN;
    }
}

void newNumberFromOddDigits(unsigned short num, unsigned short *result) {
    *result = 0;
    unsigned short digit;
    unsigned BOOL con;
    while (num) {
        digit = num % 10;
        con = IS_ODD_POINTERS(&digit);
        *result = *result * pow(TEN, con) + con * digit;
        num /= TEN;
    }
}

BOOL isPrimary(unsigned short *num) {
    unsigned sqrtN = sqrt(*num);
    unsigned short currentNumber = THREE;
    BOOL flag = IS_EVEN(*num) || currentNumber == TWO;
    while (!flag && currentNumber < sqrtN) {
        flag = *num % currentNumber;
        currentNumber += TWO;
    }
    return flag;
}

char isPerfectNumber(unsigned short num, BOOL *result) {
    unsigned short sum = ONE;
    unsigned short currentNumber;
    unsigned short maxNumber = num / TWO;
    for (currentNumber = TWO; currentNumber <= maxNumber; currentNumber++) {
        sum += currentNumber * !(num % currentNumber);
    }

    *result = (sum == num);
}

void flipNumber(unsigned short num, unsigned short *result) {
    *result = ZERO;
    while (num) {
        *result * TEN;
        *result += num % TEN;
        num /= TEN;
    }
}

void powNumber(unsigned short num, unsigned short num2, unsigned short *result) {
    *result = ONE;
    while (num2--) {
        *result *= num;
    }
}

float foo(unsigned short x0, short m, short n) {
    float x1 = x0 - (pow(x0, m) + n) / (m * pow(x0, m - ONE));
    return x1;
}

void sqrtNumber(short num, short num2, unsigned short *result) {
    unsigned short accuracy = 100;
    *result = TWO;
    num *= -ONE;
    for (; accuracy; accuracy--) {
        *result = foo(*result, num2, num);
    }
}

void multiplyNumber(unsigned short num1, unsigned short num2, unsigned short *result) {
    while (num2--) {
        *result += num1;
    }
}

void divideNumbers(unsigned short num1, unsigned short num2, unsigned short *result) {
    *result = ZERO;
    while ((num1 >= num2)) {
        *result++;
        num1 -= num2;
    }
}

void getRemainder(unsigned short num1, unsigned short num2, unsigned short *result) {
    divideNumbers(num1, num2, result);
    *result = num1 - (*result * num2);
}

void toBaseTen(unsigned short num, unsigned short base, unsigned short *result) {
    unsigned short powNumber = 0;
    while (num) {
        *result += (num % TEN) * pow(base, powNumber);
        num /= TEN;
        powNumber++;
    }
}
