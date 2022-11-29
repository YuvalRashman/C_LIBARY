//
// Created by yrash on 11/29/2022.
//

#define STACK_SIZE 4

typedef struct stack stack;
typedef int typ;

struct stack {
    typ array[STACK_SIZE];
    short top;
};

void Init_stack(stack *stack1) {
    stack1->top = -1;
}

typ Pop_stack(stack *stack1) {
    return stack1->array[stack1->top--];;
}


typ Push_stack(stack *stack1, typ value) {
    stack1->array[++stack1->top] = value;;
}

BOOL Is_Empty_Stack(stack *stack1) {
    return stack1->top == -1;
}

typ stack_Opposite(stack *stack1) {
    stack temp1;
    stack temp2;
    while (Is_Empty_Stack(stack1)) {
        Push_stack(&temp1, Pop_stack(stack1));
    }
}
