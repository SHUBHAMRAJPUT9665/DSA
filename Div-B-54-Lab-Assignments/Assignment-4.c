/*\
Write a program to implement stack as an ADT. Use this ADT to
perform expression conversion and evaluation. (Infix – Postfix)
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

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

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1; // Return a special value indicating underflow
    }
    return stack->array[stack->top--];
}

int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1; // Return a special value indicating empty stack
    }
    return stack->array[stack->top];
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int getPrecedence(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    struct Stack* stack = createStack(strlen(infix));
    int i, j;
    i = j = 0;

    while (infix[i] != '\0') {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i++];
        } else if (infix[i] == '(') {
            push(stack, infix[i++]);
        } else if (infix[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[j++] = pop(stack);
            }
            if (!isEmpty(stack) && peek(stack) == '(')
                pop(stack); // Pop the '('
            i++;
        } else if (isOperator(infix[i])) {
            while (!isEmpty(stack) && getPrecedence(infix[i]) <= getPrecedence(peek(stack))) {
                postfix[j++] = pop(stack);
            }
            push(stack, infix[i++]);
        } else {
            // Ignore other characters (whitespace, etc.)
            i++;
        }
    }

    while (!isEmpty(stack)) {
        postfix[j++] = pop(stack);
    }

    postfix[j] = '\0';
}

int evaluatePostfix(char postfix[]) {
    struct Stack* stack = createStack(strlen(postfix));
    int i, operand1, operand2, result;
    i = 0;

    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            push(stack, postfix[i] - '0');
        } else if (isOperator(postfix[i])) {
            operand2 = pop(stack);
            operand1 = pop(stack);

            switch (postfix[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
            }

            push(stack, result);
        }
        i++;
    }

    return pop(stack);
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result after evaluation: %d\n", result);

    return 0;
}
