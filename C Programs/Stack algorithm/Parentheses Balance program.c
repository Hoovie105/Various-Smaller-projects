#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

// Push operation to add an element to the top of the stack
void push(int element) {
    if (top == MAX_SIZE - 1) {
        printf("Error: Stack is full\n");
        return;
    }
    stack[++top] = element;
}

// Pop operation to remove the top element from the stack
int pop() {
    if (top == -1) {
        printf("Error: Stack is empty\n");
        return -1;
    }
    return stack[top--];
}

// IsEmpty operation to check if the stack is empty
int isEmpty() {
    return top == -1;
}

int Balance(char Bracket1, char Bracket2) {
    if (Bracket1 == '(' && Bracket2 == ')')
        return 1;
    else if (Bracket1 == '{' && Bracket2 == '}')
        return 1;
    else if (Bracket1 == '[' && Bracket2 == ']')
        return 1;
    else
        return 0;
}

void checkForBalance(char expr[]) {
    int i;
    int n = strlen(expr);

    for (i = 0; i < n; i++) {
        
        if (expr[i] != '}' && expr[i] != '{' && expr[i] != ']' && expr[i] != '[' && expr[i] != ')' && expr[i] != '(' && expr[i] != '0' && expr[i] != '1' && expr[i] != '2' && expr[i] != '3' && expr[i] != '4' && expr[i] != '5' && expr[i] != '6' && expr[i] != '7' && expr[i] != '8' && expr[i] != '9' && expr[i] != '+' && expr[i] != '-' && expr[i] != '*' && expr[i] != '/') {
            printf("Error: Invalid character\n");
            return;
        }
            
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[')
            push(expr[i]);
        if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
            if (isEmpty() || !Balance(pop(), expr[i])) {
                printf("Error: Unbalanced parentheses\n");
                return;
            }
        }
    }
    if (isEmpty())
        printf("Balanced parentheses\n");
    else
        printf("Error: Unbalanced parentheses\n");
}

int main() {
    char expr[MAX_SIZE];

    printf("Enter an arithmetic expression: ");
    scanf("%s", expr);

    checkForBalance(expr);

    return 0;
}
/*The overall run time of the code is O(n), as the entire code has only one for loop within checkForBalance(char expr[]); 
that loops over expr a number of n times. the n variable is gotten by running strlen(expr) outside
the for loop, insuring maximum efficiency.*/
