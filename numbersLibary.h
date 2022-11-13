//
// Created by yrash on 11/12/2022.
//

#include "definesLib.h"

#define IS_ODD_POINTERS(x) *x % TWO
#define IS_EVEN_POINTERS(x) !IS_ODD_POINTERS(x)

void replaceNumbers(unsigned short *pusNum1, unsigned short *pusNum2);

void sumTwoNumbers(unsigned short *pusNum1, unsigned short *pusNum2, unsigned short *pusResult);

void sumDigits(unsigned short usNum, unsigned short *pusResult);

void sumEvenDigits(unsigned short usNum, unsigned short *pusResult);

void sumOddDigits(unsigned short usNum, unsigned short *pusResult);

void isDigitInNumber(unsigned short usNum, unsigned short usDigit, BOOL *psResult);

void countDigits(unsigned short usNum, unsigned short *pusCount);

void combineTwoNumbers(unsigned short usNum1, unsigned short usNum2, unsigned short *pusResult);

void witchDigitsInNumber(unsigned short usNum, unsigned short *pusMask);

void isNumbersShareDigits(unsigned short unNum1, unsigned short unNum2, BOOL *psResult);

void newNumberFromEvenDigits(unsigned short unNum, unsigned short *pusResult);

void newNumberFromOddDigits(unsigned short unNum, unsigned short *pusResult);

void isPrimary(unsigned short unNum, BOOL *psResult);

void isPerfectNumber(unsigned short usNum, BOOL *psResult);

void flipNumber(unsigned short usNum, unsigned short *pusResult);

void powNumber(unsigned short usNum, unsigned short usExponent, unsigned short *pusResult);

void sqrtNumber(short sNum, short sExponent, unsigned short *pusResult);

void multiplyNumber(unsigned short usNum1, unsigned short usNum2, unsigned short *pusResult);

void divideNumbers(unsigned short usNum1, unsigned short usNum2, unsigned short *pusResult);

void getRemainder(unsigned short usNum1, unsigned short usNum2, unsigned short *pusResult);

void toBaseTen(unsigned short usNum, unsigned short usBase, unsigned short *pusResult);

//--------------------------------------------------------------------------------------------------------------------
//                                                  replaceNumbers
//                                                  --------------
//
// General : The function replace two numbers.
//
// Parameters :
// pusNum1 - pointer to first number (In)
// pusNum2 - pointer to second number (In)
//
// Return Value : None.
//
// O(1)
// T(n) = 3
//--------------------------------------------------------------------------------------------------------------------
void replaceNumbers(unsigned short *pusNum1, unsigned short *pusNum2) {
    *pusNum1 ^= *pusNum2;
    *pusNum2 ^= *pusNum1;
    *pusNum1 ^= *pusNum2;
}

//--------------------------------------------------------------------------------------------------------------------
//                                                  sumTwoNumbers
//                                                  -------------
//
// General : The function sum two numbers and save the pusResult in pointer.
//
// Parameters :
// pusNum1 - first number (In)
// pusNum2 - second number (In)
// pusResult - pointer to the parameter we are going to save the pusResult (In)
//
// Return Value : None.
//
// O(1)
// T(n) = 1
//--------------------------------------------------------------------------------------------------------------------
void sumTwoNumbers(unsigned short *pusNum1, unsigned short *pusNum2, unsigned short *pusResult) {
    *pusResult = *pusNum1 + *pusNum2;
}

//--------------------------------------------------------------------------------------------------------------------
//                                                    sumDigits
//                                                    ---------
//
// General : The function sum all the digits of a number and save the pusResult in pointer.
//
// Parameters :
// usNum - the number (In)
// pusResult - pointer to the parameter we are going to save the pusResult (In)
//
// Return Value : None.
//
// O(n)
// T(n) = 3n + 1
//--------------------------------------------------------------------------------------------------------------------
void sumDigits(unsigned short usNum, unsigned short *pusResult) {
    *pusResult = ZERO;
    while (usNum) {
        *pusResult += usNum % TEN;
        usNum /= TEN;
    }
}

//--------------------------------------------------------------------------------------------------------------------
//                                                  sumEvenDigits
//                                                  -------------
//
// General : The function sum the even digits of a number and save the pusResult in pointer.
//
// Parameters :
// usNum - the number (In)
// pusResult - pointer to the parameter we are going to save the pusResult (In)
//
// Return Value : None.
//
// O(n)
// T(n) = 4n + 1
//--------------------------------------------------------------------------------------------------------------------
void sumEvenDigits(unsigned short usNum, unsigned short *pusResult) {
    unsigned short usDigit;
    *pusResult = ZERO;
    while (usNum) {
        usDigit = usNum % TEN;
        *pusResult += IS_EVEN(usDigit) * usDigit;
        usNum /= TEN;
    }
}

//--------------------------------------------------------------------------------------------------------------------
//                                                  sumOddDigits
//                                                  -------------
//
// General : The function sum the odd digits of a number and save the pusResult in pointer.
//
// Parameters :
// usNum - the number (In)
// pusResult - pointer to the parameter we are going to save the pusResult (In)
//
// Return Value : None.
//
// O(n)
// T(n) = 7n + 4
//--------------------------------------------------------------------------------------------------------------------
void sumOddDigits(unsigned short usNum, unsigned short *pusResult) {
    unsigned short usTemp = ZERO;
    sumDigits(usNum, *pusResult);
    sumEvenDigits(usNum, &usTemp);
    *pusResult -= usTemp;
}

//--------------------------------------------------------------------------------------------------------------------
//                                                  combineTwoNumbers
//                                                  -----------------
//
// General : This function combine two numbers to one.
//
// Parameters :
// num1 - first number (In)
// num2 - second number (In)
// psResult -  pointer to the parameter we are going to save the psResult (In)
//
// Return Value : None.
//
// O(n)
// T(n) = 4n + 1
//--------------------------------------------------------------------------------------------------------------------
void isDigitInNumber(unsigned short usNum, unsigned short usDigit, BOOL *psResult) {
    *psResult = FALSE;
    while (usNum && !(*psResult)) {
        *psResult = usNum % TEN == usDigit;
        usNum /= TEN;
    }
}

//--------------------------------------------------------------------------------------------------------------------
//                                                  countDigits
//                                                  -------------
//
// General : This function pusCount the number of digits in number.
//
// Parameters :
// usNum - the number (In)
// pusCount - pointer to the parameter we are going to save the result (In)
//
// Return Value : None.
//
// O(n)
// T(n) = 3n + 1
//--------------------------------------------------------------------------------------------------------------------
void countDigits(unsigned short usNum, unsigned short *pusCount) {
    *pusCount = ZERO;
    while (usNum) {
        *pusCount++;
        usNum /= TEN;
    }
}

//--------------------------------------------------------------------------------------------------------------------
//                                                  combineTwoNumbers
//                                                  -----------------
//
// General : This function combine two numbers to one.
//
// Parameters :
// usNum1 - first number (In)
// usNum2 - second number (In)
// pusResult -  pointer to the parameter we are going to save the pusResult (In)
//
// Return Value : None.
//
// O(n)
// T(n) = 5n + 4
//--------------------------------------------------------------------------------------------------------------------
void combineTwoNumbers(unsigned short usNum1, unsigned short usNum2, unsigned short *pusResult) {
    *pusResult = ZERO;
    countDigits(usNum2, pusResult);
    powNumber(TEN, *pusResult, pusResult);
    *pusResult = usNum1 * (*pusResult) + usNum2;
}

//--------------------------------------------------------------------------------------------------------------------
//                                                  witchDigitsInNumber
//                                                  -----------------
//
// General : This function check witch digits in number.
//
// Parameters :
// num1 - first number (In)
// num2 - second number (In)
// pusMask -  pointer to the parameter we are going to save the result, the result save as pusMask (10bits) each bit
// represent a different digit (In)
//
// Return Value : None.
//
// O(n)
// T(n) = 3n + 1
//--------------------------------------------------------------------------------------------------------------------
void witchDigitsInNumber(unsigned short usNum, unsigned short *pusMask) {
    *pusMask = ZERO;
    while (usNum) {
        *pusMask |= ONE << (usNum % TEN);
        usNum /= TEN;
    }
}

//--------------------------------------------------------------------------------------------------------------------
//                                                  isNumbersShareDigits
//                                                  -------------------
//
// General : This function check if two numbers share digits.
//
// Parameters :
// unNum1 - first number (In)
// unNum2 - second number (In)
// psResult -  pointer to the parameter we are going to save the psResult (In)
//
// Return Value : None.
//
// O(1)
// T(n) = 6n + 3
//--------------------------------------------------------------------------------------------------------------------
void isNumbersShareDigits(unsigned short unNum1, unsigned short unNum2, BOOL *psResult) {
    unsigned short usMask1;
    unsigned short usMask2;
    witchDigitsInNumber(unNum1, &usMask1);
    witchDigitsInNumber(unNum2, &usMask2);
    *psResult = (usMask1 & usMask2) != ZERO;
}

//--------------------------------------------------------------------------------------------------------------------
//                                                  newNumberFromEvenDigits
//                                                  ----------------------
//
// General : This function create new number from only the even digits of a number.
//
// Parameters :
// unNum - the number (In)
// pusResult -  pointer to the parameter we are going to save the pusResult (In)
//
// Return Value : None.
//
// O(n)
// T(n) = 6n + 1
//--------------------------------------------------------------------------------------------------------------------
void newNumberFromEvenDigits(unsigned short unNum, unsigned short *pusResult) {
    unsigned short usDigit;
    unsigned short usPowNumber;
    BOOL sCon;
    *pusResult = ZERO;
    while (unNum) {
        usDigit = unNum % TEN;
        sCon = IS_EVEN_POINTERS(&usDigit);
        powNumber(TEN, sCon, &usPowNumber);
        *pusResult = *pusResult * usPowNumber + sCon * usDigit;
        unNum /= TEN;
    }
}

//--------------------------------------------------------------------------------------------------------------------
//                                                  newNumberFromOddDigits
//                                                  ----------------------
//
// General : This function create new number from only the Odd digits of a number.
//
// Parameters :
// unNum - the number (In)
// pusResult -  pointer to the parameter we are going to save the pusResult (In)
//
// Return Value : None.
//
// O(n)
// T(n) = 6n + 1
//--------------------------------------------------------------------------------------------------------------------
void newNumberFromOddDigits(unsigned short unNum, unsigned short *pusResult) {
    unsigned short usDigit;
    unsigned short usPowNumber;
    BOOL sCon;
    *pusResult = ZERO;
    while (unNum) {
        usDigit = unNum % TEN;
        sCon = IS_ODD_POINTERS(&usDigit);
        powNumber(TEN, sCon, &usPowNumber);
        *pusResult = *pusResult * usPowNumber + sCon * usDigit;
        unNum /= TEN;
    }
}

//--------------------------------------------------------------------------------------------------------------------
//                                                    isPrimary
//                                                    ---------
//
// General : This function check if a number is prime number.
//
// Parameters :
// unNum - the number (In)
// psResult -  pointer to the parameter we are going to save the psResult (In)
//
// Return Value : None.
//
// O(log(n))
// T(n) = 2log(n) + 2
//--------------------------------------------------------------------------------------------------------------------
void isPrimary(unsigned short unNum, BOOL *psResult) {
    unsigned short usSqrtN;
    unsigned short usCurrentNumber = THREE;
    sqrtNumber(unNum, TWO, &usSqrtN);
    *psResult = IS_EVEN(unNum) || usCurrentNumber == TWO;
    while (!(*psResult) && usCurrentNumber < usSqrtN) {
        *psResult = unNum % usCurrentNumber;
        usCurrentNumber += TWO;
    }
}

//--------------------------------------------------------------------------------------------------------------------
//                                                    isPerfectNumber
//                                                    --------------
//
// General : This function check if a number is perfect number.
//
// Parameters :
// usNum - the number (In)
// psResult -  pointer to the parameter we are going to save the psResult (In)
//
// Return Value : None.
//
// O(n)
// T(n) = 3n + 3
//--------------------------------------------------------------------------------------------------------------------
void isPerfectNumber(unsigned short usNum, BOOL *psResult) {
    unsigned short usSum = ONE;
    unsigned short usCurrentNumber;
    unsigned short usMaxNumber = usNum / TWO;
    for (usCurrentNumber = TWO; usCurrentNumber <= usMaxNumber; usCurrentNumber++) {
        usSum += usCurrentNumber * !(usNum % usCurrentNumber);
    }
    *psResult = (usSum == usNum);
}

//--------------------------------------------------------------------------------------------------------------------
//                                                    isPerfectNumber
//                                                    --------------
//
// General : This function flip a number example: 123 turn to 321.
//
// Parameters :
// usNum - the number (In)
// pusResult -  pointer to the parameter we are going to save the pusResult (In)
//
// Return Value : None.
//
// O(n)
// T(n) = 4n + 1
//--------------------------------------------------------------------------------------------------------------------
void flipNumber(unsigned short usNum, unsigned short *pusResult) {
    *pusResult = ZERO;
    while (usNum) {
        *pusResult * TEN;
        *pusResult += usNum % TEN;
        usNum /= TEN;
    }
}

//--------------------------------------------------------------------------------------------------------------------
//                                                    powNumber
//                                                    ---------
//
// General : This function power a number by n.
//
// Parameters :
// usNum - the number to pow (In)
// usExponent - the exponent number (In)
// pusResult -  pointer to the parameter we are going to save the pusResult (In)
//
// Return Value : None.
//
// O(n)
// T(n) = 2n + 1
//--------------------------------------------------------------------------------------------------------------------
void powNumber(unsigned short usNum, unsigned short usExponent, unsigned short *pusResult) {
    *pusResult = ONE;
    while (usExponent--) {
        *pusResult *= usNum;
    }
}

//--------------------------------------------------------------------------------------------------------------------
//                                                    sqrtNumber
//                                                    ---------
//
// General : This function sqrt a number by n.
//
// Parameters :
// sNum - the number to sqrt (In)
// sExponent - the exponent number (In)
// pusResult -  pointer to the parameter we are going to save the pusResult (In)
//
// Return Value : None.
//
// O(1)
// T(n) = 7
//--------------------------------------------------------------------------------------------------------------------
void sqrtNumber(short sNum, short sExponent, unsigned short *pusResult) {
    unsigned short usAccuracy = 100;
    unsigned short usPowNumber;
    *pusResult = TWO;
    sNum *= -ONE;
    for (; usAccuracy; usAccuracy--) {
        powNumber(*pusResult, sExponent, &usPowNumber);
        *pusResult -= (usPowNumber + sNum) / (sExponent * (usPowNumber / *pusResult));
    }
}

//--------------------------------------------------------------------------------------------------------------------
//                                                    multiplyNumber
//                                                    ------------
//
// General : This function replace * and multiply two numbers.
//
// Parameters :
// usNum1 - the first number (In)
// usNum2 - the second number (In)
// pusResult -  pointer to the parameter we are going to save the pusResult (In)
//
// Return Value : None.
//
// O(n)
// T(n) = 2
//--------------------------------------------------------------------------------------------------------------------
void multiplyNumber(unsigned short usNum1, unsigned short usNum2, unsigned short *pusResult) {
    while (usNum2--) {
        *pusResult += usNum1;
    }
}

//--------------------------------------------------------------------------------------------------------------------
//                                                    divideNumbers
//                                                    ------------
//
// General : This function replace / and divide two numbers.
//
// Parameters :
// usNum1 - the first number (In)
// usNum2 - the second number (In)
// pusResult -  pointer to the parameter we are going to save the pusResult (In)
//
// Return Value : None.
//
// O(n)
// T(n) = 3n + 1
//--------------------------------------------------------------------------------------------------------------------
void divideNumbers(unsigned short usNum1, unsigned short usNum2, unsigned short *pusResult) {
    *pusResult = ZERO;
    while ((usNum1 >= usNum2)) {
        *pusResult++;
        usNum1 -= usNum2;
    }
}

//--------------------------------------------------------------------------------------------------------------------
//                                                    divideNumbers
//                                                    ------------
//
// General : This function replace % and get the remainder of two numbers.
//
// Parameters :
// usNum1 - the first number (In)
// usNum2 - the second number (In)
// pusResult -  pointer to the parameter we are going to save the pusResult (In)
//
// Return Value : None.
//
// O(n)
// T(n) = 3n + 2
//--------------------------------------------------------------------------------------------------------------------
void getRemainder(unsigned short usNum1, unsigned short usNum2, unsigned short *pusResult) {
    divideNumbers(usNum1, usNum2, pusResult);
    *pusResult = usNum1 - (*pusResult * usNum2);
}

//--------------------------------------------------------------------------------------------------------------------
//                                                    toBaseTen
//                                                    ---------
//
// General : This function turn number from usBase n to usBase 10.
//
// Parameters :
// usNum - the first number (In)
// usBase - the usBase of the number usNum (In)
// pusResult -  pointer to the parameter we are going to save the pusResult (In)
//
// Return Value : None.
//
// O(n)
// T(n) = 5n + 2 
//--------------------------------------------------------------------------------------------------------------------
void toBaseTen(unsigned short usNum, unsigned short usBase, unsigned short *pusResult) {
    unsigned short usPowNumber = ZERO;
    unsigned short usTemp;
    while (usNum) {
        powNumber(usBase, usPowNumber, &usTemp);
        *pusResult += (usNum % TEN) * usTemp;
        usNum /= TEN;
        usPowNumber++;
    }
}
