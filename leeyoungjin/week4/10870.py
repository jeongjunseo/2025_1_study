# parameter N < 20 / -> 피보나치 수 구하기 문제
import sys

def fibonacci(N): # 피보나치 함수를 재귀적으로 만든다
    if N == 0: # 0이면 0
        return 0
    if (N == 1): # 1이면 1
        return 1
    else: # 1 이상이면 N-1과 N-2를 재귀 호출
        return fibonacci(N-1)+fibonacci(N-2)


n = int(sys.stdin.readline()) # N 입력받기
result = fibonacci(n)
print(result) # 프린트 ~~~~~



