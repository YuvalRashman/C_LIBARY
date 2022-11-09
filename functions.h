#pragma once

#include "definesLib.h"

#ifndef FUNCSIONS
#include "../../../OneDrive/Documents/אורט סינגלובסקי/שיעורי בית מכללה/defineFunctions.h"
#define FUNCSIONS
#endif // !FUNCSIONS

#define BOOL char

int sqrt(int num);

double pow(double a, int b) {
	int power = 1, currentPow;
	for (currentPow = 1; currentPow <= b; currentPow++) {
		power = power * a;
	}
	return power;
}

short countDigits(unsigned int num) {
	short counter = 0;
	while (num)
	{
		counter++;
		num /= 10;
	}
	return counter;
}

int sumDigits(int num) {
	int sum = 0;
	while (num)
	{
		sum += num % 10;
		num /= 10;
	}
	return sum;
}

int sumEvenDigits(int num) {
	int sum = 0, digit;
	while (num)
	{
		digit = num % 10;
		sum += IS_EVEN(digit) * digit;
		num /= 10;
	}
	return sum;
}

int sumOddDigits(int num) {
	return sumDigits(num) - sumEvenDigits(num);
}

char isDigitInNumber(int num, short digit) {
	while (num)
	{
		if (!(num % 10 - digit)) {
			return 1;
		}
	}
	return 0;
}

short digitIndexInNumber(int num, short digit) {
	int index = 0;
	while (num)
	{
		if (!(num % 10 - digit))
		{
			return index;
		}
		index++;
	}
	return -1;
}

short countDigitInNumber(int num, short digit) {
	int counter = 0;
	while (num)
	{
		counter += !(num % 10 - digit);
		num /= 10;
	}
	return counter;
}

char isNumbersHaveRelatedDigits(int num1, int num2) {
	int coppyN2 = num2;
	while (num1 > 0)
	{
		if (!((num1 % 10) - (num2 % 10)))
		{
			return 1;
		}
		num2 /= 10;
		if (num2 < 1)
		{
			num2 = coppyN2;
			num1 /= 10;
		}
	}
}

short maxDigitInNumber(int num) {
	int max = num % 10;
	while (num)
	{
		max = MAX(max, (num % 10));
		num /= 10;
	}
	return max;
}

int combineTwoNumbers(int num1, unsigned int num2) {
	return num1 * pow(10, countDigits(num2)) + num2;
}

int createNumberFromEvenDigits(int num) {
	int newNum;
	while (num * (num % 10) % 2)
	{
		num /= 10;
	}
	newNum = num % 10;
	while (num)
	{
		if ((num % 10) % 2)
		{
			combineTwoNumbers(newNum, (num % 10));
		}
	}
}

int createNumberFromOddDigits(int num) {
	int newNum;
	while (num * !((num % 10) % 2))
	{
		num /= 10;
	}
	newNum = num % 10;
	while (num)
	{
		if (!((num % 10) % 2))
		{
			combineTwoNumbers(newNum, (num % 10));
		}
	}
}

short creteNumberFromTwoMaxDigits(int num1, int num2) {
	return combineTwoNumbers(maxDigitInNumber(num1), maxDigitInNumber(num2));
}

char isPrimary(int *num) {
	unsigned sqrtN = sqrt(*num);
    unsigned short currentNumber = 3;
    BOOL flag = IS_ODD(*num) && currentNumber < sqrtN;
    while(flag ){
        
    }
	return 1;
}

char isContainAPrimeDigit(int num) {
	while (num)
	{
		if (isPrimary(num % 10))
		{
			return 1;
		}
		num /= 10;
	}
	return 0;
}

int newNumberOfPrimeDigits(int num1, int num2) { // black box
	int newNumber = 0;
	short digit;
	while (num1)
	{
		digit = num1 % 10;
		newNumber *= pow(10, isPrimary(digit));
		newNumber += isPrimary(digit) * digit;
		num1 /= 10;
	}
	while (num2)
	{
		digit = num2 % 10;
		newNumber *= pow(10, isPrimary(digit));
		newNumber += isPrimary(digit) * digit;
		num2 /= 10;
	}
	return newNumber;
}

int countPrimeDigits(int num) {
	int primeDigitCounter = 0;
	while (num)
	{
		primeDigitCounter += isPrimary(num % 10);
		num /= 10;
	}
	return primeDigitCounter;
}

char isPerfectNumber(int num) {
	int sum = 0, currentNumber;
	for (currentNumber = 1; currentNumber <= (num / 2); currentNumber++)
	{
		sum += currentNumber * !(num % currentNumber);
	}
	return !(sum - num);
}

int flipNumber(int num) {
	int flipNum = 0;
	while (num)
	{
		flipNum *= 10;
		flipNum += num % 10;
		num /= 10;
	}
	return flipNum;
}

char isFilandrom(int num) {
	return !(flipNumber(num) - num);
}

int multiply(int a, int b) {
	int sum = 0;
	for (; b > 0; b--) {
		sum += a;
	}
	return sum;
}

int division(int num1, int num2)
{
	int temp = 1, reasult = 0;
	while (num2 <= num1)
	{
		num2 <<= 1;
		temp <<= 1;
	}
	while (temp > 1)
	{
		num2 >>= 1;
		temp >>= 1;
		if (num1 >= num2)
		{
			num1 -= num2;
			reasult += temp;
		}
	}
	return reasult;
}

float remainder(int num1, int num2) {
	return num1 - division(num1, num2) * num2;
}

int sqrt(int num) {
	int numberToCheck, sqrt = 0;
	for (numberToCheck = 1; numberToCheck <= (num / 2); numberToCheck++)
	{
		sqrt += !(numberToCheck * numberToCheck - num) * numberToCheck;
	}
	return sqrt;
}

int sqrtByExponent(int a, int b) {
	int baseNumber = 1;
	while (pow(baseNumber, b) < a)
	{
		baseNumber++;
	}
	return baseNumber;
}

int baseTen(int num, int base) {
	int baseTenNumber = 0, powNumber = 0;
	while (num)
	{
		baseTenNumber += num % 10 * pow(base, powNumber);
		powNumber++;
		num /= 10;
	}
	return baseTenNumber;
}

short getYear(int date) {
	int digit, year = 0;
	for (digit = 0; digit < 4; digit++)
	{
		year *= 10;
		year += date % 10;
		date /= 10;
	}
	return flipNumber(year);
}

short getMonth(int date) {
	int digit, month = 0;
	date /= 10000;
	for (digit = 0; digit < 2; digit++)
	{
		month *= 10;
		month += date % 10;
		date /= 10;
	}
	return flipNumber(month);
}

short getDay(int date) {
	int digit, day = 0;
	date /= 1000000;
	for (digit = 0; digit < 2; digit++)
	{
		day *= 10;
		day += date % 10;
		date /= 10;
	}
	return flipNumber(day);
}

int dateToDays(int date) {
	return getYear(date) * 365 + getMonth(date) * 31 + getDay(date);
}

int timeDifrence(int date1, int date2) { // need to be ddmmyyyy
	int daysDiff = ABS((dateToDays(date1) - dateToDays(date2)));
	return daysDiff;
}

int removeDigit(int num, short digit) {
	int newNum = 0;
	while (num)
	{
		newNum *= pow(10, !(!((num % 10) - digit)));
		newNum += !(!((num % 10) - digit)) * (num % 10);
		num /= 10;
	}
	return flipNumber(newNum);
}

int removeMaxDigit(int num) {
	return removeDigit(num, maxDigitInNumber(num));
}

short secondLargestDigit(int num) {
	int reminder, max = 0, secMax = 0;
	while (num > 0)
	{
		reminder = num % 10;
		if (max < reminder)
		{
			secMax = max;
			max = reminder;
		}
		else {
			secMax = MAX(secMax, reminder);
		}
		num = num / 10;
	}
	return secMax;
}

int removeSecondMaxDigit(int num) {
	return removeDigit(num, secondLargestDigit(num));
}

int newNumberFromDevision(int num, int n) {
	int newNumber = 0, digit;
	while (num)
	{
		digit = num % 10;
		newNumber *= pow(10, !(digit % n));
		newNumber += !(digit % n) * digit;
		num /= 10;
	}
	return newNumber;
}