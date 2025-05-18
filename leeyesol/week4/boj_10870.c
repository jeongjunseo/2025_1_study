#include <stdio.h>

// 피보나치 수열을 계산하는 함수 선언
int fibonacci(int n);

int main(void){
    int n;
    // 사용자로부터 정수 입력 받기
    scanf("%d", &n);

    // n번째 피보나치 수 출력
    printf("%d\n", fibonacci(n));
}

// 피보나치 수열의 n번째 수를 재귀적으로 계산하는 함수
int fibonacci(int n){
    if(n == 0)
        return 0; // 0번째 피보나치 수는 0
    else if(n == 1)
        return 1; // 1번째 피보나치 수는 1
    else
        // n번째 피보나치 수는 (n-1)번째 + (n-2)번째
        return fibonacci(n - 1) + fibonacci(n - 2);
}
