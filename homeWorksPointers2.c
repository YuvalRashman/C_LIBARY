//
// Created by yrash on 11/13/2022.
//

// first option
int StrLen(char *s) {
    char *start = s;
    while (*(start++));
    return ((--start) - s);
}

// second option
int StrLen(char *s) {
    int Len = 0;
    while (*s) {
        s++;
        Len++;
    }
    return Len;
}

// third option
int StrLen(char *s) {
    int Len = 0;
    for (; *(s++); Len++);
    return Len;
}

char *SearchCharInString(char *str, char tav) {
    char *start = str;
    while (*(start++) != tav);
    return (*(--start) == tav);
}

void Reverse(char *str) {
    char *EndStr = (str + (StrLen(str) - 1));
    while (EndStr++ > str--) {
        Swap(str, EndStr);
    }
}

int CountTavInString(char *str, char *tav) {
    int count = 0;
    while (*str++) {
        count = *str == *tav ? 1 : 0;
    }
    return count;
}

BOOL CompareStr(char *str1, char *str2) {
    while ((*str2) * (*str1) * (*(str1++) == *(str2++)));
    return *(--str1) == *(--str2);
}

void Shirshor(char *str1, char *str2) {
    str1 += StrLen(str1);
    while (*(str1++) = *(str2++));
}

void StrCopy(char *str1, char *str2) {
    while (str2)
        *(str1++) = *(str2++);
}