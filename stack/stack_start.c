//
// Created by yrash on 11/29/2022.
//

#include <stdio.h>

#define STACK_SIZE 4
#define BOOL char
#define FALSE 0
#define EMPTY_STACK -1 // the EOD if the stack is empty

typedef struct stack stack;
typedef int typ; // the kind of value  that inside the stack.

struct stack {
    typ array[STACK_SIZE];
    short usTop;
};

void Init_stack(stack *stack1);

typ Pop_stack(stack *stack1);

void Push_stack(stack *stack1, typ value);

BOOL Is_Empty_Stack(stack *stack1);

void Opposite_stack(stack *stack1);

void Copy_stack(stack stackToCopy, stack *copy);

void Opposite_part_of_stack(stack stackToCopy, stack *copy, unsigned short usAmount);

BOOL If_num_in_stack(stack stack1, typ value);

unsigned short Total_items_in_stack(stack stack1);

BOOL criterion(typ value);

void Split_Stack(stack *stack1, stack *stack2, stack *stack3);

void United_stack(stack *stack1, stack *stack2);

void Empty_stack(stack *stack1);

BOOL Is_Equal_Stack(stack stack1, stack stack2);

unsigned short Sum_Stack(stack stack1);

void Print_Stack(stack stack1);

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
    stack1->usTop = EMPTY_STACK;
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
    return (stack1->array[(stack1->usTop--)]);;
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
    stack1->array[++(stack1->usTop)] = value;;
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
    return stack1->usTop == EMPTY_STACK;
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
    Init_stack(&temp1);
    stack temp2;
    Init_stack(&temp2);
    while (Is_Empty_Stack(stack1)) {
        Push_stack(&temp1, Pop_stack(stack1));
    }
    while (Is_Empty_Stack(&temp1)) {
        Push_stack(&temp2, Pop_stack(&temp1));
    }
    while (Is_Empty_Stack(&temp2)) {
        Push_stack(stack1, Pop_stack(&temp2));
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
// copy - the stack we want to copy to (In)
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
// usAmount - the amount we want to copy (In)
//
// m - the amount to copy
// Runtime function: T(m) 3m + 1 --> O(m).
//
// nesting level : 1
//
// Return Value : None.
//
//--------------------------------------------------------------------------------------------------------------------
void Opposite_part_of_stack(stack stackToCopy, stack *copy, unsigned short usAmount) {
    Init_stack(copy);
    while (usAmount > 0) {
        Push_stack(copy, Pop_stack(&stackToCopy));
        usAmount--;
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
        flag = stack1.array[stack1.usTop--] == value;
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
    unsigned short usCount = 0;
    while (Is_Empty_Stack(&stack1)) {
        usCount++;
        Pop_stack(&stack1);
    }
    return usCount;
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
        criterion(temp) ? Push_stack(stack2, temp) : Push_stack(stack1, temp);
    }
}

// --------------------------------------------------------------------------------------------------------------------
//                                                         United_stack
//                                                         ------------
//
// General : The function unite two stacks to one save in the left stack.
//
// Parameters :
// stack1 - the first stack and the stack where the result will be save (In)
// stack2 - the second stack()  (In)
//
// Runtime function: T(n) 2n --> O(n).
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

// --------------------------------------------------------------------------------------------------------------------
//                                                         Empty_stack
//                                                         ------------
//
// General : The function empty the given stack.
//
// Parameters :
// stack1 - the stack to empty (In)
//
// Runtime function: None.
//
// nesting level : 0
//
// Return Value : None.
//
//--------------------------------------------------------------------------------------------------------------------
void Empty_stack(stack *stack1) {
    Init_stack(stack1);
}

// --------------------------------------------------------------------------------------------------------------------
//                                                         Is_Equal_Stack
//                                                         --------------
//
// General : The function check if two stacks equal.
//
// Parameters :
// stack1 - the first stack (In)
// stack2 - the second stack (In)
//
// Runtime function: 3n + 2 --> O(n).
//
// nesting level : 1
//
// Return Value : 1 if the stacks are equal, 0 if not.
//
//--------------------------------------------------------------------------------------------------------------------
BOOL Is_Equal_Stack(stack stack1, stack stack2) {
    BOOL flag;
    flag = Total_items_in_stack(stack1) == Total_items_in_stack(stack2);
    while (flag && Is_Empty_Stack(&stack1)) {
        flag = Pop_stack(&stack1) == Pop_stack(&stack2);
    }
    return flag;
}

// --------------------------------------------------------------------------------------------------------------------
//                                                         Is_Equal_Stack
//                                                         --------------
//
// General : The function sum all values in the stack.
//
// Parameters :
// stack1 - the stack to sum (In)
//
// Runtime function: 2n + 2 --> O(n).
//
// nesting level : 1
//
// Return Value : the sum.
//
//--------------------------------------------------------------------------------------------------------------------
unsigned short Sum_Stack(stack stack1) {
    unsigned short usSum = 0;
    while (Is_Empty_Stack(&stack1)) {
        usSum = Pop_stack(&stack1);
    }
    return usSum;
}

// --------------------------------------------------------------------------------------------------------------------
//                                                         Is_Equal_Stack
//                                                         --------------
//
// General : The function print the stack.
//
// Parameters :
// stack1 - the stack to print (In)
//
// Runtime function: 8n --> O(n).
//
// nesting level : 1.
//
// Return Value : None.
//
//--------------------------------------------------------------------------------------------------------------------
void Print_Stack(stack stack1) {
    Opposite_stack(&stack1);
    while (Is_Empty_Stack(&stack1)) {
        printf("%d", Pop_stack(&stack1));
    }
}
