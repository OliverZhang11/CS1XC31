#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


int simpleParse(const char *exp);

typedef struct int_stack int_stack;

struct int_stack {
  int top_index;
  int arr[10];
};

void push(int_stack *stack, int n) {
  (*stack).arr[(*stack).top_index + 1] = n;
  (*stack).top_index++;
}

int top(int_stack stack) {
  return stack.arr[stack.top_index];
}

void pop(int_stack *stack) {
  (*stack).top_index--;
}

int empty(int_stack stack) 
  return stack.top_index == -1;
}

int precedence(char op) {
  if(op == '+'||op == '-')
  return 1;
  if(op == '*'||op == '/'||op == '%')
  return 2;
  return 0;
}

int applyOp(int a, int b, char op) {
  switch(op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    case '%': return a % b;
    }
}

int simpleParse(char *exp) {
  int i, len = strlen(exp);
  int_stack values; 
  values.top_index = -1;
  int_stack ops; 
  ops.top_index = -1;
  for(i = 0; i < len; i++) {
    if(exp[i] == ' ') 
    continue;
    if(isdigit(exp[i])) { 
      int val = 0;
      while(i < len && isdigit(exp[i])) {
        val = (val*10) + (exp[i]-'0');
        i++;
        }
      push(&values, val);
      i--;
      }
    else {
      while(!empty(ops) && precedence(top(ops)) >= precedence(exp[i])) {
        int val2 = top(values);
        pop(&values);
        int val1 = top(values);
        pop(&values);
        char op = top(ops);
        pop(&ops);
        push(&values, applyOp(val1, val2, op));
        }
      push(&ops, exp[i]);
      }
    }

    while(!empty(ops)) { 
      int val2 = top(values);
      pop(&values);
      int val1 = top(values);
      pop(&values);
      char op = top(ops);
      pop(&ops);
      push(&values, applyOp(val1, val2, op));
      }
    return top(values);
}

int main() {
    char exp1[] = "2 + 2";
    printf("%s = %d\n", exp1, simpleParse(exp1));
	// Expected Value = 4
    char exp2[] = "3 + 7 - 4 * 1";
	printf("%s = %d\n", exp2, simpleParse(exp2));
	// Expected Value = 6
    char exp3[] = "9 * 13 / 2 + 18 * 110 - 812 \% 97 + 3";
   	printf("%s = %d\n", exp3, simpleParse(exp3));
	// Expected Value = 2005
}
