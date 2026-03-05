/*Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int precedence(char op) {
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

int main() {
    char infix[100], postfix[100];
    int i, k = 0;

    scanf("%s", infix);

    for(i = 0; infix[i] != '\0'; i++) {

        char ch = infix[i];

        if(isalnum(ch)) {
            postfix[k++] = ch;
        }

        else if(ch == '(') {
            push(ch);
        }

        else if(ch == ')') {
            while(top != -1 && peek() != '(') {
                postfix[k++] = pop();
            }
            pop();
        }

        else {
            while(top != -1 && precedence(peek()) >= precedence(ch)) {
                postfix[k++] = pop();
            }
            push(ch);
        }
    }

    while(top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';

    printf("%s", postfix);

    return 0;
}