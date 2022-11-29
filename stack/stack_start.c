//
// Created by yrash on 11/29/2022.
//

#include <stdio.h>

#define STACK_SIZE 4
#define BOOL char
#define EMPTY_STACK -1 // the EOD if the stack is empty

typedef struct stack stack;
typedef int typ; // the kind of value  that inside the stack.

struct stack {
    typ array[STACK_SIZE];
    short top;
};

void Init_stack(stack *stack1);
typ Pop_stack(stack *stack1);



// --------------------------------------------------------------------------------------------------------------------
//                                                         Init_stack
//                                                         -----------
//
// General : The function initialize a new stack.
//
// Parameters :
// stack1 - pointer to the stack we want to initialize (In)
//
// Runtime function: None
//
// nesting level : 0
//
// Return Value : None.
//
//--------------------------------------------------------------------------------------------------------------------
void Init_stack(stack *stack1) {
    stack1->top = EMPTY_STACK;
}

// --------------------------------------------------------------------------------------------------------------------
//                                                         Pop_stack
//                                                         ----------
//
// General : The function delete the top value and return him.
//
// Parameters :
// stack1 - pointer to the stack (In)
//
// Runtime function: None.
//
// nesting level : 0
//
// Return Value : the deleted value / the last top value.
//
//--------------------------------------------------------------------------------------------------------------------
typ Pop_stack(stack *stack1) {
    return stack1->array[stack1->top--];;
}


// --------------------------------------------------------------------------------------------------------------------
//                                                         Push_stack
//                                                         -----------
//
// General : The function add new item to the stack.
//
// Parameters :
// stack1 - pointer to the stack (In)
// value - the value to add (In)
//
// Runtime function: None.
//
// nesting level : 0
//
// Return Value :None.
//
//--------------------------------------------------------------------------------------------------------------------
void Push_stack(stack *stack1, typ value) {
    stack1->array[++stack1->top] = value;;
}

// --------------------------------------------------------------------------------------------------------------------
//                                                         Is_Empty_Stack
//                                                         --------------
//
// General : The function check if the stack is empty.
//
// Parameters :
// stack1 - pointer to the stack (In)
// value - the value to add (In)
//
// Runtime function: None.
//
// nesting level : 0
//
// Return Value : 1 if the stack is empty and 0 if the stack is not empty.
//
//--------------------------------------------------------------------------------------------------------------------
BOOL Is_Empty_Stack(stack *stack1) {
    return stack1->top == EMPTY_STACK;
}

// --------------------------------------------------------------------------------------------------------------------
//                                                         Opposite_stack
//                                                         --------------
//
// General : The function flip the stack.
//
// Parameters :
// stack1 - pointer to the stack (In)
//
// Runtime function: T(n) 2n + 2n +  2n = 6n --> O(n).
//
// nesting level : 1
//
// Return Value : None.
//
//--------------------------------------------------------------------------------------------------------------------
void Opposite_stack(stack *stack1) {
    stack temp1;
    Init_stack(temp1);
    stack temp2;
    Init_stack(temp2);
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

// --------------------------------------------------------------------------------------------------------------------
//                                                         Copy_stack
//                                                         -----------
//
// General : The function flip the stack.
//
// Parameters :
// stackToCopy -  the stack to copy from (In)
// copy - the stack we want to copy to In)
//
// Runtime function: T(n) 2n + 2n +  2n = 6n --> O(n).
//
// nesting level : 1
//
// Return Value : None.
//
//--------------------------------------------------------------------------------------------------------------------
void Copy_stack(stack stackToCopy, stack *copy) {
    Init_stack(copy);
    while (Is_Empty_Stack(&stackToCopy)) {
        Push_stack(copy, Pop_stack(&stackToCopy));
    }
    Opposite_stack(copy);
}

// --------------------------------------------------------------------------------------------------------------------
//                                                         Opposite_part_of_stack
//                                                         ----------------------
//
// General : The function copy a certain amount of values from the stack.
//
// Parameters :
// stackToCopy -  the stack to copy from (In)
// copy - the stack we want to copy to (In)
// amount - the amount we want to copy (In)
//
// m - the amount to copy
// Runtime function: T(m) 3m + 1 --> O(m).
//
// nesting level : 1
//
// Return Value : None.
//
//--------------------------------------------------------------------------------------------------------------------
void Opposite_part_of_stack(stack stackToCopy, stack *copy, unsigned short amount) {
    Init_stack(copy);
    while (amount > 0) {
        Push_stack(copy, Pop_stack(stackToCopy));
        amount--;
    }
}

// --------------------------------------------------------------------------------------------------------------------
//                                                         If_num_in_stack
//                                                         ---------------
//
// General : The function check if a value is inside the stack.
//
// Parameters :
// stack1 - the stack to check (In)
// value - the value to search for (In)
//
// Runtime function: T(n) 3n + 2 --> O(n).
//
// nesting level : 1
//
// Return Value : 1 if the value found and 0 instead.
//
//--------------------------------------------------------------------------------------------------------------------
BOOL If_num_in_stack(stack stack1, typ value) {
    BOOL flag = FALSE;
    while (!flag && Is_Empty_Stack(&stack1)) {
        flag = stack1.array[stack1.top--] == value;
    }
    return flag;
}

// --------------------------------------------------------------------------------------------------------------------
//                                                         Total_items_in_stack
//                                                         --------------------
//
// General : The function count how many items there is in the stack.
//
// Parameters :
// stack1 - the stack (In)
//
// Runtime function: T(n) 3n + 2 --> O(n).
//
// nesting level : 1
//
// Return Value : the number of items in the stack.
//
//--------------------------------------------------------------------------------------------------------------------
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

// --------------------------------------------------------------------------------------------------------------------
//                                                         Split_Stack
//                                                         -----------
//
// General : The function split the stack to two stack according to the criterion().
//
// Parameters :
// stack1 - the stack to split (In)
// stack2 - the values that sustain the criterion()  (In)
// stack3 - the values that doesn't sustain the criterion()  (In)
//
// Runtime function: T(n) 4n + 2 --> O(n).
//
// nesting level : 1
//
// Return Value : None.
//
//--------------------------------------------------------------------------------------------------------------------
void Split_Stack(stack *stack1, stack *stack2, stack *stack3) {
    Init_stack(stack2);
    Init_stack(stack3);
    typ temp;
    while (Is_Empty_Stack(stack1)) {
        temp = Pop_stack(stack1);
        criterion(typ) ? Push_stack(stack2, temp) : Push_stack(stack1, temp);
    }
}

// --------------------------------------------------------------------------------------------------------------------
//                                                         United_stack
//                                                         ------------
//
// General : The function split the stack to two stack according to the criterion().
//
// Parameters :
// stack1 - the stack to split (In)
// stack2 - the values that sustain the criterion()  (In)
// stack3 - the values that doesn't sustain the criterion()  (In)
//
// Runtime function: T(n) 4n + 2 --> O(n).
//
// nesting level : 1
//
// Return Value : None.
//
//--------------------------------------------------------------------------------------------------------------------
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

unsigned short getMiddleValue(stack stack1) {
    while ((temp = Pop_stack(stack1)) < Pop_stack(stack1));
    return temp;
}

