//
// Created by yrash on 11/19/2022.
//

#include "stringL.h"
#include "definesLib.h"

typedef struct date date;
typedef struct book book;

struct date {
    short year;
    short day;
    short month;
    BOOL isCount;
};

struct book {
    string book_name;
    string author_name;
    string publish_company_name;
    unsigned short publish_year;
    unsigned short price;
    unsigned short serial_number;
};


void main() {
    book book1 = {"The book", "yuval", "cool", 2004, 200,
                  1};
    book book2;
    scanf("%s", &(book2.author_name));
    scanf("%s", &(book2.book_name));
    scanf("%s", &(book2.publish_company_name));
    scanf("%d", &(book2.publish_year));
    scanf("%d", &(book2.price));
    scanf("%d", &(book2.serial_number));
}