import sys
from collections import deque # queue 라이브러리 가져오기

input = sys.stdin.readline 
n = int(input())
dq = deque()

for _ in range(n):
    command = input().strip() # 명령 받구
    
    if command.startswith("1 "):  # 앞에 추가
        _, x = command.split()
        dq.appendleft(int(x))
    elif command.startswith("2 "):  # 뒤에 추가
        _, x = command.split()
        dq.append(int(x))
    elif command == "3":  # 앞에서 제거
        print(dq.popleft() if dq else -1)
    elif command == "4":  # 뒤에서 제거
        print(dq.pop() if dq else -1)
    elif command == "5":  # 크기 출력
        print(len(dq))
    elif command == "6":  # 비어있는지 확인
        print(0 if dq else 1)
    elif command == "7":  # 앞의 값 출력
        print(dq[0] if dq else -1)
    elif command == "8":  # 뒤의 값 출력
        print(dq[-1] if dq else -1)
