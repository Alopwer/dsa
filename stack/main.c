#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Stack {
    int top;
    int size;
    // count can be removed if we don't print the stack
    int count;
    // not defined as array so we can allocate memory dynamically
    // instead we can use int items[]
    // but when allocating memory for stack, we need to use this:
    // stack *s = (stack *) malloc(sizeof(stack) + size * sizeof(int))
    int *items;
};

// define type for easier access
typedef struct Stack stack;

// return address in memory of the stack
stack* createEmptyStack(int size) {
    // allocate memory for stack
    stack *s = (stack*) malloc(sizeof(stack));
    s->top = -1;
    s->count = 0;
    s->size = size;
    s->items = (int*) malloc(s->size * sizeof(int));
    return s;
}

int isFull(stack *s) {
  if (s->top == s->size - 1)
    return 1;
  else
    return 0;
}

int isEmpty(stack *s) {
  if (s->top == -1)
    return 1;
  else
    return 0;
}

int peek(stack *s) {
    if (isEmpty(s))
        return INT_MIN;
    else
        return s->items[s->top];
}

void push(stack *s, int number) {
    if (isFull(s)) return;
    s->items[++s->top] = number;
    s->count++;
}

void pop(stack *s) {
    if (isEmpty(s)) return;
    s->top--;
    s->count--;
}

void print(stack *s) {
    for (int i = 0; i < s->count; i++) {
        printf("%d ", s->items[i]);
    }
}

int main() {
    int size;
    scanf("%d", &size);
    stack *s = createEmptyStack(size);
    pop(s);
    push(s, 1);
    printf("%d", peek(s));
    printf("\n");
    pop(s);
    push(s, 10);
    push(s, 25);
    push(s, 5);
    print(s);
    return 0;
}