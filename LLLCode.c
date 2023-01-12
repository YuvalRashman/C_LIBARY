//
// Created by yrash on 1/10/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(x, y) (x > y) ? x : y
#define BIGGER(x, y) (x > y) ? TRUE : FALSE
#define SMALLER(x, y) (x > y) ? FALSE : TRUE
#define MIN(x, y) (x < y) ? x : y
#define EQUAL(x, y) !(x - y)
#define NOTEQUAL(x, y) !!(x - y)
#define POSITIVE(x) (0 < x) ? TRUE : FALSE
#define ABS(x) (0 < x) ? x : -x
#define MAXSIZE 100
#define TEN 10
#define TWO 2
#define FIVE 5
#define ZERO 0
#define ONE 1
#define FALSE 0
#define TRUE 1
#define TYP char*
#define bool char
#define us unsigned short


typedef char type*;

typedef struct LinearLinkedList {
    type value;
    struct LinearLinkedList *next;
} LinearLinkedList;

typedef LinearLinkedList* Manger;

void InitLLL(Manger *managerPtr)// first node
{
    *managerPtr = NULL;
}

// push to the first place
void PushLLL(Manger *manager) {
    LinearLinkedList *nodePtr = (LinearLinkedList *) malloc(sizeof(LinearLinkedList));
    nodePtr->next = *manager;
    *manager = nodePtr;
}

// push to place(not first)
void AddAfterLLL(LinearLinkedList *nodePtr) {
    LinearLinkedList *newNodePtr = (LinearLinkedList *) malloc(sizeof(LinearLinkedList));
    newNodePtr->next = nodePtr->next;
    nodePtr->next = newNodePtr;

}

// pop the first place
void PopLLL(Manger *manager) {
    LinearLinkedList *temp = *manager;
    // *value = (*manager)->value;
    *manager = temp->next;
    free(temp);
}

// pop to place(not first)
void DeleteAfterLLL(LinearLinkedList *nodePtr) {
    LinearLinkedList *temp = nodePtr->next;
    // *valuePtr = temp->value;
    nodePtr->next = temp->next;
    free(temp);
}


void copyString(char source[], char *destination) {
    int offset = 0;
    while (source[offset]) {
        *destination = source[offset];
        destination++;
        offset++;
    }

    *destination = '\0'; // add '\0' at the end
}

// print LLL
void printLLL(LinearLinkedList *nodePtr) {
    while (nodePtr != NULL) {
        printf("%s ", (nodePtr->value));
        nodePtr = nodePtr->next;
    }
}


void main() {

    LinearLinkedList *lll;
    LinearLinkedList *move;
    us vec[16] = {0};

    char value[10] = "asfs", alue[10] = "adfd", aldue[10] = "udfd";
    InitLLL(&lll);
    PushLLL(&lll);
    //copyString("value", (move->value));
    char a[4] = "sss";
    char * b = strdup(a);
    //strcpy(move->value, b);
    /*AddAfterLLL(move);
    move = move->next;*/
    move->value = b;
    //copyString("value", (move->value));
    printLLL(lll);
}