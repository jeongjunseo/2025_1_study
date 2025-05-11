import sys

array = [] # 리스트 선언
for i in range(15): # 공백 있으면 break 걸고 15줄까지 입력 받기 -> 공백 있으면 2차원 배열로 들어가요
    line = sys.stdin.readline().rstrip() # input 받기
    if line == "": # 공백이라면
        break 
    else:
        array.append(list(line)) #line을 list화시키고 array에 append

max_len = max(len(line) for line in array) # 가장 긴 행 구하기

for i in range(max_len): # 행
    for j in range(len(array)): # 열 -> 각 행의 array 길이
        if i < len(array[j]): # index 범위 체크
            print(array[j][i], end = "") # 공백없이 일렬로 쭉 ~~~~
    
    
