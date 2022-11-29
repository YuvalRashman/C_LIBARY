//
// Created by yrash on 11/29/2022.
//

#include <stdio.h>

#define STACK_SIZE 4
#define BOOL char
#define TRUE 1
#define FALSE 0
#define EMPTY_STACK -1

typedef struct stack stack;
typedef int typ;

struct stack {
    typ array[STACK_SIZE];
    short top;
};

void Init_stack(stack *stack1) {
    stack1->top = EMPTY_STACK;
}

typ Pop_stack(stack *stack1) {
    return stack1->array[stack1->top--];;
}


typ Push_stack(stack *stack1, typ value) {
    stack1->array[++stack1->top] = value;;
}

BOOL Is_Empty_Stack(stack *stack1) {
    return stack1->top == EMPTY_STACK;
}

typ Opposite_stack(stack *stack1) {
    stack temp1;
    stack temp2;
    while (Is_Empty_Stack(stack1)) {
        Push_stack(&temp1, Pop_stack(stack1));
    }
    while (Is_Empty_Stack(temp1)) {
        Push_stack(&temp2, Pop_stack(temp1));
    }
    while (Is_Empty_Stack(temp2)) {
        Push_stack(&stack1, Pop_stack(temp2));
    }
}

void Copy_stack(stack stackToCopy, stack *copy) {
    while (Is_Empty_Stack(&stackToCopy)) {
        Push_stack(copy, Pop_stack(&stackToCopy));
    }
    Opposite_stack(copy);
}

void Opposite_part_of_stack(stack stackToCopy, stack *copy, unsigned short amount) {
    while (amount > 0) {
        Push_stack(copy, Pop_stack(stackToCopy));
        amount--;
    }
    Opposite_stack(copy);
}

BOOL If_num_in_stack(stack stack1, typ value) {
    BOOL flag = FALSE;
    while (!flag && Is_Empty_Stack(&stack1)) {
        flag = stack1.array[stack1.top--] == value;
    }
    return flag;
}

unsigned short Total_items_in_stack(stack stack1) {
    unsigned short count = 0;
    while (Is_Empty_Stack(&stack1)) {
        count++;
        Pop_stack(&stack1);
    }
    return count;
}

BOOL criterion(typ value) {
    return value % 2 == 0;
}

void Split_Stack(stack *stack1, stack *stack2, stack *stack3) {
    typ temp;
    while (Is_Empty_Stack(stack1)) {
        temp = Pop_stack(stack1);
        criterion(typ) ? Push_stack(stack2, temp) : Push_stack(stack1, temp);
    }
}

void United_stack(stack *stack1, stack *stack2) {
    while (Is_Empty_Stack(stack2)) {
        Push_stack(stack1, Pop_stack(stack2));
    }
}

void Empty_stack(stack *stack1) {
    Init_stack(stack1);
}

void Is_Equal_Stack(stack stack1, stack stack2) {
    BOOL flag;
    flag = Total_items_in_stack(stack1) == Total_items_in_stack(stack2);
    while (flag && Is_Empty_Stack(stack1)) {
        flag = Pop_stack(stack1) == Pop_stack(stack2);
    }
    return flag;
}

unsigned short Sum_Stack(stack stack1) {
    unsigned short sum = 0;
    while (Is_Empty_Stack(stack1)) {
        sum = Pop_stack(stack1);
    }
    return sum;
}

void Print_Stack(stack stack1) {
    unsigned short items = Total_items_in_stack(stack1);
    for (; items > 0; items--) {
        printf("%d", Pop_stack(stack1));
    }
}

7.    start
8.
define variables
a.
stack stack1
b.
typ tepm
9.    while(
temp = pop(stack1) < pop(stack1)
);

unsigned short getMiddleValue(stack stack1) {
    while ((temp = Pop_stack(stack1)) < Pop_stack(stack1));
    return temp;
}
