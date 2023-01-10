//
// Created by yrash on 1/10/2023.
//

#ifndef LINEAR_LINKED_LIST
#define LINEAR_LINKED_LIST

#include <stdlib.h>

typedef int typ;

typedef struct LinearLinkedListNode {
    typ info;
    struct LinearLinkedListNode *next;
} LinearLinkedListNode;

void Push(LinearLinkedListNode **manager, typ value);

void Pop(LinearLinkedListNode **manager);

void InsertAfter(LinearLinkedListNode *node, typ value);

void RemoveAfter(LinearLinkedListNode *node);

#endif




