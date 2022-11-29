//
// Created by yrash on 11/29/2022.
//

#define STACK_SIZE 4

typedef struct stack stack;

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


