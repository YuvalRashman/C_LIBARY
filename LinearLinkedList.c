//
// Created by yrash on 1/10/2023.
//

#include "LinearLinkedList.h"

void Push(LinearLinkedListNode **manager, typ value) {
    LinearLinkedListNode *node = (LinearLinkedListNode *) malloc(sizeof(LinearLinkedListNode));
    node->info = value;
    node->next = *manager;
    *manager = node;
}


void Pop(LinearLinkedListNode **manager) {
    LinearLinkedListNode *ptr = (*manager);
    manager = (*manager)->next;
    free(ptr);
}

void InsertAfter(LinearLinkedListNode *node, typ value) {
    LinearLinkedListNode *newNode = (LinearLinkedListNode *) malloc(sizeof(LinearLinkedListNode));
    node->info = value;
    newNode->next = node->next;
    node->next = newNode;
}

void RemoveAfter(LinearLinkedListNode *node) {
    LinearLinkedListNode *ptr = node->next;
    node->next = (node->next)->next;
    free(ptr);
}