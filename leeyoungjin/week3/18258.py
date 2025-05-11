import sys
from collections import deque # queue 관련 라이브러리 가져오기

input = sys.stdin.readline # 시간 단축을 위해 sys 라이브러리 사용
n = int(input()) # temp 개수
queue = deque() 

for _ in range(n): # 명령 수 만큼
    command = input().strip() # command 받고
     
    if command.startswith("push"):
        _, num = command.split()
        queue.append(int(num)) # push
    elif command == "pop":
        if queue:
            print(queue.popleft()) # pop
        else:
            print(-1)
    elif command == "size":
        print(len(queue)) # 사이즈 출력
    elif command == "empty":
        print(0 if queue else 1) 
    elif command == "front":
        print(queue[0] if queue else -1)
    elif command == "back":
        print(queue[-1] if queue else -1)
