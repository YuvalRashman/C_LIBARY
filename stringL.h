#pragma once

#include <stdio.h>

#ifndef STRINGL
#define STRINGL
#endif // !STRINGL

#include "definesLib.h"

#define EOD '\0'
#define ZERO_INDEX '0'

typedef char string[256];

BOOL isContain(string str, char ch, unsigned short usStartOffset);

BOOL isStringsEqual(string str1, string str2);

BOOL isPolyndromous(string str);

BOOL isSubstring(string str, string sub, unsigned short usStartOffset);

unsigned short indexOf(string str, char ch, unsigned short usStartOffset);

unsigned short countCharInString(string str, char ch, unsigned short usStartOffset);

unsigned short length(string str);

unsigned short indexOfSubstring(string str, string sub, unsigned short usStartOffset);

unsigned short countSubstring(string str, string sub);

unsigned int toInt(string str);

void copy(string str1, string str2, unsigned short usStart, unsigned short usEnd);

void copyFromChar(string str1, string str2, char ch);

void concatenation(string str1, string str2);

void reverse(string str);

void toString(string str, unsigned int unNum);

void cut(string str, unsigned short usStartOffset, unsigned short usEndOffset);

void deleteSubstring(string str, string sub, unsigned short startOffset);

void addSubstring(string str, string sub, unsigned short usOffset);

//--------------------------------------------------------------------------------------------------------------------
//                                                  indexOf
//                                                  -------
//
// General : The function find the offset of char in string.
//
// Parameters :
// str - string to go throw (In)
// ch - char to find (In)
// usStartIndex - offset to start (In)
//
// Return Value : the offset of ch in str.
//
//--------------------------------------------------------------------------------------------------------------------
unsigned short indexOf(string str, char ch, unsigned short usStartOffset) {
    while (str[usStartOffset] * (str[usStartOffset++] - ch));
    return --usStartOffset;
}

//--------------------------------------------------------------------------------------------------------------------
//                                                  isContain
//                                                  ---------
//
// General : The function check if char exist in string.
//
// Parameters :
// str - string to go throw (In)
// ch - char to find (In)
// usStartOffset - offset to start (In)
//
// Return Value : true or false.
//
//--------------------------------------------------------------------------------------------------------------------
BOOL isContain(string str, char ch, unsigned short usStartOffset) {
    return str[indexOf(str, ch, usStartOffset)] == ch;
}

//--------------------------------------------------------------------------------------------------------------------
//                                                  countCharInString
//                                                  -----------------
//
// General : The function check how much times char exist in string.
//
// Parameters :
// str - string to go throw (In)
// ch - char to find (In)
// usStartOffset - offset to start (In)
//
// Return Value : short number that represent the number of times.
//
//--------------------------------------------------------------------------------------------------------------------
unsigned short countCharInString(string str, char ch, unsigned short usStartOffset) {
    unsigned short usCount = ZERO;
    while ((str[usStartOffset++] - ch) ? str[usStartOffset] : ++usCount);
    return usCount;
}

//--------------------------------------------------------------------------------------------------------------------
//                                                  length
//                                                  ------
//
// General : The function check the length of strinng.
//
// Parameters :
// str - string to check (In)
//
// Return Value : short number that represent the length of the string.
//
//--------------------------------------------------------------------------------------------------------------------
unsigned short length(string str) {
    unsigned short usCount = ZERO;
    while (str[usCount++]);
    return --usCount;
}

//--------------------------------------------------------------------------------------------------------------------
//                                                  isStringsEqual
//                                                  --------------
//
// General : The function check if 2 strings equal.
//
// Parameters :
// str1 - first string (In)
// str2 - second string (In)
//
// Return Value : true or false.
//
//--------------------------------------------------------------------------------------------------------------------
BOOL isStringsEqual(string str1, string str2) {
    unsigned short usOffset = ZERO;
    while (str1[usOffset] * str2[usOffset] * (str1[usOffset] == str2[usOffset++]));
    usOffset--;
    return str1[usOffset] == str2[usOffset];
}

//--------------------------------------------------------------------------------------------------------------------
//                                                       copy
//                                                       ----
//
// General : The function copy string to another string from offset to offset.
//
// Parameters :
// str1 - first string (In)
// str2 - second string (In)
// usStart - offset to start
// usEnd - offset to end
//
// Return Value : None.
//
//--------------------------------------------------------------------------------------------------------------------
void copy(string str1, string str2, unsigned short usStart, unsigned short usEnd) {
    unsigned short usOffset;
    for (usOffset = ZERO; usStart < usEnd; str1[usOffset] = str2[usStart], usStart++, usOffset++);
    str1[usOffset] = EOD;
}

//--------------------------------------------------------------------------------------------------------------------
//                                                       copyFromChar
//                                                       ------------
//
// General : The function copy string to another string from specific char.
//
// Parameters :
// str1 - first string (In)
// str2 - second string (In)
// ch - char to start copy from him
//
// Return Value : None.
//
//--------------------------------------------------------------------------------------------------------------------
void copyFromChar(string str1, string str2, char ch) {
    copy(str1, str2, indexOf(str2, ch, ZERO), length(str2));
}

//--------------------------------------------------------------------------------------------------------------------
//                                                       concatenation
//                                                       -------------
//
// General : The function take 2 strings and combine them.
//
// Parameters :
// str1 - first string (In)
// str2 - second string (In)
//
// Return Value : None.
//
//--------------------------------------------------------------------------------------------------------------------
void concatenation(string str1, string str2) {
    unsigned short usStr1Length = length(str1);
    unsigned short usOffset;
    for (usOffset = ZERO; str2[usOffset]; str1[usOffset + usStr1Length] = str2[usOffset++]);
    str1[usOffset + usStr1Length] = EOD;
}

//--------------------------------------------------------------------------------------------------------------------
//                                                       reverse
//                                                       -------
//
// General : The function reverse the string.
//
// Parameters :
// str - string (In)
//
// Return Value : None.
//
//--------------------------------------------------------------------------------------------------------------------
void reverse(string str) {
    unsigned short usStrEndOffset;;
    unsigned short usOffset;
    unsigned short usStrLength = length(str);
    unsigned short usIsEven = !(usStrLength % TWO);
    for (usOffset = ZERO, usStrEndOffset = usStrLength - ONE; (usIsEven + usStrEndOffset) != usOffset;
         str[usStrEndOffset] ^= str[usOffset], str[usOffset] ^= str[usStrEndOffset], str[usStrEndOffset] ^= str[usOffset], usOffset++, usStrEndOffset--);
}

//--------------------------------------------------------------------------------------------------------------------
//                                                       isPolyndromous
//                                                       --------------
//
// General : The function check if string is polyndromous the same from both sides.
//
// Parameters :
// str - string (In)
//
// Return Value : true or false.
//
//--------------------------------------------------------------------------------------------------------------------
BOOL isPolyndromous(string str) {
    string reverseStr;
    copy(reverseStr, str, ZERO, length(str));
    reverse(reverseStr);
    return isStringsEqual(str, reverseStr);
}

//--------------------------------------------------------------------------------------------------------------------
//                                                         toInt
//                                                         -----
//
// General : The function convert string to Integer number (int).
//
// Parameters :
// str - string (In)
//
// Return Value : Integer number that equal to the string.
//
//--------------------------------------------------------------------------------------------------------------------
unsigned int toInt(string str) {
    unsigned int unResult;
    unsigned short usOffset;
    for (unResult = ZERO, usOffset = ZERO; str[usOffset]; unResult += (str[usOffset] -
                                                                       ZERO_INDEX), unResult *= TEN, usOffset++);
    unResult /= 10;
    return unResult;
}

//--------------------------------------------------------------------------------------------------------------------
//                                                         toString
//                                                         --------
//
// General : The function convert Integer number (int) to string.
//
// Parameters :
// str - string to save the result (In)
// unNum - the number to convert (In)
//
// Return Value : string that equal to the Integer number (int).
//
//--------------------------------------------------------------------------------------------------------------------
void toString(string str, unsigned int unNum) {
    unsigned short usOffset;
    for (usOffset = ZERO; unNum; str[usOffset] = (ZERO_INDEX + unNum % TEN), unNum /= TEN, usOffset++);
    str[usOffset] = '\0';
    reverse(str);
}

//--------------------------------------------------------------------------------------------------------------------
//                                                        cut
//                                                        ---
//
// General : The function cut the string to from offset to offset.
//
// Parameters :
// str - string to cut (In)
// usStart - offset to start
// usEnd - offset to end
//
// Return Value : None.
//
//--------------------------------------------------------------------------------------------------------------------
void cut(string str, unsigned short usStartOffset, unsigned short usEndOffset) {
    unsigned short usOffset;
    unsigned short usStrLength = length(str);
    usStrLength -= (usEndOffset - usStartOffset);
    for (usOffset = ZERO; (usOffset + usStartOffset) <= usStrLength; str[usStartOffset + usOffset] = str[usEndOffset +
                                                                                                         usOffset], usOffset++);
    str[usStartOffset + usOffset] = EOD;
}

//--------------------------------------------------------------------------------------------------------------------
//                                                        indexOfSubstring
//                                                        ----------------
//
// General : The function find the first indext where substring start.
//
// Parameters :
// str - string to check (In)
// sub - the substring (In)
// usStartOffset - offset to start
//
// Return Value : Integer number that indicates where the substring start.
//
//--------------------------------------------------------------------------------------------------------------------
unsigned short indexOfSubstring(string str, string sub, unsigned short usStartOffset) {
    string str3;
    unsigned short usStr2Length = length(sub);
    unsigned short usIndex = indexOf(str, sub[ZERO], usStartOffset);
    copy(str3, str, usIndex, (usIndex + usStr2Length));
    while (str[usIndex] * !isStringsEqual(str3, sub)) {
        usIndex = indexOf(str, sub[ZERO], (usIndex + ONE));
        copy(str3, str, usIndex, usIndex + usStr2Length);
    }
    return usIndex;
}

//--------------------------------------------------------------------------------------------------------------------
//                                                        isSubstring
//                                                        -----------
//
// General : The function check if string is substring of another string.
//
// Parameters :
// str - string to check (In)
// sub - the substring to check (In)
// usStartOffset - offset to start
//
// Return Value : true or false.
//
//--------------------------------------------------------------------------------------------------------------------
BOOL isSubstring(string str, string sub, unsigned short usStartOffset) {
    string str3;
    unsigned short usIndex = indexOfSubstring(str, sub, usStartOffset);
    copy(str3, str, usIndex, usIndex + length(sub));
    return isStringsEqual(str3, sub);
}

//--------------------------------------------------------------------------------------------------------------------
//                                                        countSubstring
//                                                        --------------
//
// General : The function count the show amounts of string in another string (substring).
// 
// Parameters :
// str - string to check (In)
// sub - the substring to check (In)
//
// Return Value : number that indicates the amount of appearances.
//
//--------------------------------------------------------------------------------------------------------------------
unsigned short countSubstring(string str, string sub) {
    unsigned short usCount = ZERO;
    unsigned short usIndex = indexOfSubstring(str, sub, ZERO);
    while (isSubstring(str, sub, usIndex)) {
        usCount++;
        usIndex = indexOfSubstring(str, sub, usIndex + ONE);
    }
    return usCount;
}

//--------------------------------------------------------------------------------------------------------------------
//                                                        countSubstring
//                                                        --------------
//
// General : The function delete all the shows of substring from chosen string.
// 
// Parameters :
// str - string to check (In)
// sub - the substring to check (In)
//
// Return Value : None.
//
//--------------------------------------------------------------------------------------------------------------------
void deleteSubstring(string str, string sub, unsigned short startOffset) {
    unsigned short usStrLength = length(str);
    unsigned short usSub2Length = length(sub);
    unsigned short usIndex = indexOfSubstring(str, sub, startOffset);
    while (usStrLength > usIndex) {
        cut(str, usIndex, (usIndex + usSub2Length));
        usStrLength = length(str);
        usIndex = indexOfSubstring(str, sub, usIndex);
    }
}

//--------------------------------------------------------------------------------------------------------------------
//                                                        addSubstring
//                                                        ------------
//
// General : The function add string in another string from specific offset.
// 
// Parameters :
// str - string to check (In)
// sub - the substring to check (In)
// usOffset - where to enter sub (In)
//
// Return Value : None.
//
//--------------------------------------------------------------------------------------------------------------------
void addSubstring(string str, string sub, unsigned short usOffset) {
    string strCut;
    copy(strCut, str, usOffset, length(str));
    cut(str, usOffset, length(str));
    concatenation(str, sub);
    concatenation(str, strCut);
}