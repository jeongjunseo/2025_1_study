#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    if (top == -1) return -1;
    return stack[top--];
}

int size() {
    return top + 1;
}

int empty() {
    return (top == -1) ? 1 : 0;
}

int top_value() {
    if (top == -1) return -1;
    return stack[top];
}

int main() {
    int n, command, x;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &command);
        switch (command) {
            case 1:
                scanf("%d", &x);
                push(x);
                break;
            case 2:
                printf("%d\n", pop());
                break;
            case 3:
                printf("%d\n", size());
                break;
            case 4:
                printf("%d\n", empty());
                break;
            case 5:
                printf("%d\n", top_value());
                break;
        }
    }

    return 0;
}
