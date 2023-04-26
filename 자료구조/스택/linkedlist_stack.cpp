#include <iostream>
#include <cstddef>
typedef int element;
typedef struct StackNode{
    element data;
    StackNode * link;
}StackNode;

typedef struct linkedStack{
    StackNode * top;
}linkedStack;

void init(linkedStack *stack){    
    stack->top = nullptr;
}

bool is_empty(linkedStack *stack){
    return stack->top == nullptr;
}

void push(linkedStack *stack, element data){
    StackNode *temp = (StackNode *)malloc(sizeof(StackNode));

    if(temp == nullptr){
        std::cerr << "Memory Allocation Error\n";
        return;
    }
    temp->data = data;
    temp->link = stack->top;
    stack->top = temp;
}
element pop(linkedStack *stack){
    if(is_empty(stack)){
        std::cerr << "Stack is Empty\n";
        exit(-1);
    }
    StackNode *temp = stack->top;
    stack->top = stack->top->link;

    element data = temp->data;
    free(temp);
    return data;
}

element peek(linkedStack *stack){
    if(is_empty(stack)){
        std::cerr << "Stack is Empty\n";
        exit(-1);
    }
    return stack->top->data;
}

int main(){
    linkedStack stack;
    
    init(&stack);
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    std::cout << pop(&stack) << "\n";
    std::cout << pop(&stack) << "\n";
    std::cout << peek(&stack) << "\n";
    std::cout << pop(&stack) << "\n";
    std::cout << is_empty(&stack) << "\n";
}
