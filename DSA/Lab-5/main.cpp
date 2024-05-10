#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return 1;
    return 0;
}

int precedence(char c) {
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}

int isOpeningBracket(char c) {
    if (c == '(' || c == '{' || c == '[')
        return 1;
    return 0;
}

int isClosingBracket(char c) {
    if (c == ')' || c == '}' || c == ']')
        return 1;
    return 0;
}

int isMatchingBracket(char opening, char closing) {
    if (opening == '(' && closing == ')')
        return 1;
    if (opening == '{' && closing == '}')
        return 1;
    if (opening == '[' && closing == ']')
        return 1;
    return 0;
}

int isBalanced(char *exp) {
    char stack[MAX_SIZE];
    int top = -1;
    for (int i = 0; i < strlen(exp); i++) {
        if (isOpeningBracket(exp[i])) {
            stack[++top] = exp[i];
        } else if (isClosingBracket(exp[i])) {
            if (top == -1 || !isMatchingBracket(stack[top], exp[i])) {
                return 0;
            }
            top--;
        }
    }
    if (top == -1) {
        return 1;
    }
    return 0;
}

int isdigit(char c) {
    if (c >= '0' && c <= '9') {
        return 1;
    }
    return 0;
}

void infixToPostfix(char *src, char *dst) {
    if (!isBalanced(src)) {
        printf("Error: unbalanced brackets\n");
        return;
    }
    char stack[MAX_SIZE];
    int top = -1;
    int j = 0;
    for (int i = 0; i < strlen(src); i++) {
        char c = src[i];
        if (isdigit(c)) {
            dst[j++] = c;
        } else if (isOperator(c)) {
            while (top != -1 && stack[top] != '(' && precedence(stack[top]) >= precedence(c)) {
                dst[j++] = stack[top--];
            }
            stack[++top] = c;
        } else if (isOpeningBracket(c)) {
            stack[++top] = c;
        } else if (isClosingBracket(c)) {
            while (top != -1 && !isOpeningBracket(stack[top])) {
                dst[j++] = stack[top--];
            }
            top--;  // remove the opening bracket from the stack
        }
    }
    while (top != -1) {
        if (isOpeningBracket(stack[top])) {
            printf("Error: unbalanced brackets\n");
            return;
        }
        dst[j++] = stack[top--];
    }
    dst[j] = '\0';
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
