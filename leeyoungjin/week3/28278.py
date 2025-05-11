import sys

input = sys.stdin.read
commands = input().splitlines()

stack = []

for command in commands[1:]:  # 첫 줄은 temp이므로 제외
    if command.startswith("1"):
        _, num = command.split() # push
        stack.append(int(num))
    elif command == "2":
        if stack:
            print(stack.pop()) # pop
        else:
            print(-1)
    elif command == "3":
        print(len(stack)) # 현재 스택의 길이 print
    elif command == "4":
        print(0 if stack else 1) # if stack => 0이 아니면 1을 반환
    elif command == "5":
        if stack: # 정수가 있나요 ? 
            print(stack[-1]) # 맨위의 스택 -> 인덱스는 0부터 시작이니까 -1
        else:
            print(-1)  # 없으면 -1 출력
