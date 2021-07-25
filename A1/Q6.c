#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
struct Stack {
  int top;
  unsigned capacity;
  int* array;
};

struct Stack* createStack(unsigned capacity) {
  struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
  stack->capacity = capacity;
  stack->top = -1;
  stack->array = (int*)malloc(stack->capacity * sizeof(int));
  return stack;
}
int isFull(struct Stack* stack) {
  return stack->top == stack->capacity - 1;
} 
int isEmpty(struct Stack* stack) {
  return stack->top == -1;
}
  
void push(struct Stack* stack, int item) {
  if (isFull(stack))
    return;
  stack->array[++stack->top] = item;
  printf("%d pushed to stack\n", item);
}
  
int pop(struct Stack* stack) {
  if (isEmpty(stack))
    return INT_MIN;
  return stack->array[stack->top--];
}
  
int peek(struct Stack* stack) {
  if (isEmpty(stack))
    return INT_MIN;
  return stack->array[stack->top];
}
  
int main() {
  struct Stack* stack = createStack(100);
  
  push(stack, 1);
  push(stack, 2);
  push(stack, 3);
  push(stack, 4);
  push(stack, 5);
  push(stack, 6);
  
  printf("\n\n%d popped from stack\n", pop(stack));
  printf("%d popped from stack\n", pop(stack));
  
return 0;
}
