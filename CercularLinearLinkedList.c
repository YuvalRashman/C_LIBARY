//
// Created by yrash on 1/10/2023.
//

#include "CircularLinearLinkedList.h"

void InsertEnd(CircularLinearLinkedListNode **manager, typ value) {
    CircularLinearLinkedListNode *newNode = (CircularLinearLinkedListNode *) malloc(
            sizeof(CircularLinearLinkedListNode));
    newNode->info = value;
    newNode->next = (*manager)->next; // equal to first
    (*manager)->next = newNode;
    *manager = newNode;
}

// first time use
void InsertLast(CircularLinearLinkedListNode **manager, typ value) {
    CircularLinearLinkedListNode *newNode = (CircularLinearLinkedListNode *) malloc(
            sizeof(CircularLinearLinkedListNode));
    newNode->next = NULL;
    newNode->info = value;
    *manager = newNode;
}

// N > 1
void DeleteEnd(CircularLinearLinkedListNode **manager) {
    CircularLinearLinkedListNode *ptr = *manager;
    *manager = (*manager)->next;
    free(ptr);
}

// first time use N = 1
void DeleteLast(CircularLinearLinkedListNode **manager) {
    free(manager);
    *manager = NULL;
}

void InsertAfter(CircularLinearLinkedListNode *node, typ value) {
    CircularLinearLinkedListNode *newNode = (CircularLinearLinkedListNode *) malloc(
            sizeof(CircularLinearLinkedListNode));
    node->info = value;
    newNode->next = node->next;
    node->next = newNode;
}

void DeleteAfter(CircularLinearLinkedListNode *node) {
    CircularLinearLinkedListNode *ptr = node->next;
    node->next = (node->next)->next;
    free(ptr);
}


