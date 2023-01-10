//
// Created by yrash on 1/10/2023.
//

#ifndef C_LIBARY_CIRCULARLINEARLINKEDLIST_H
#define C_LIBARY_CIRCULARLINEARLINKEDLIST_H

#include <stdlib.h>

typedef int typ;

typedef struct CircularLinearLinkedListNode {
    typ info;
    struct CircularLinearLinkedListNode *next;
} CircularLinearLinkedListNode;

void InsertEnd(CircularLinearLinkedListNode **manager, typ value);

void InsertLast(CircularLinearLinkedListNode **manager, typ value);

void InsertAfter(CircularLinearLinkedListNode *node, typ value);

void DeleteAfter(CircularLinearLinkedListNode *node);

void DeleteEnd(CircularLinearLinkedListNode **manager);

void DeleteLast(CircularLinearLinkedListNode **manager);

#endif //C_LIBARY_CIRCULARLINEARLINKEDLIST_H
