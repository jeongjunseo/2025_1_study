#include <stdio.h>

#define MAX 2000000

int deque[MAX];
int front = MAX / 2;
int back = MAX / 2;

void push_front(int x) {
    deque[--front] = x;
}

void push_back(int x) {
    deque[back++] = x;
}

int pop_front() {
    if (front == back) return -1;
    return deque[front++];
}

int pop_back() {
    if (front == back) return -1;
    return deque[--back];
}

int size() {
    return back - front;
}

int empty() {
    return (front == back) ? 1 : 0;
}

int front_value() {
    if (empty()) return -1;
    return deque[front];
}

int back_value() {
    if (empty()) return -1;
    return deque[back - 1];
}

int main() {
    int n, cmd, x;
    scanf("%d", &n);

    while (n--) {
        scanf("%d", &cmd);
        switch (cmd) {
            case 1:
                scanf("%d", &x);
                push_front(x);
                break;
            case 2:
                scanf("%d", &x);
                push_back(x);
                break;
            case 3:
                printf("%d\n", pop_front());
                break;
            case 4:
                printf("%d\n", pop_back());
                break;
            case 5:
                printf("%d\n", size());
                break;
            case 6:
                printf("%d\n", empty());
                break;
            case 7:
                printf("%d\n", front_value());
                break;
            case 8:
                printf("%d\n", back_value());
                break;
        }
    }

    return 0;
}
