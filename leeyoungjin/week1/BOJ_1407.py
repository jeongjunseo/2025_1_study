

nums = list(map(int,list(input()))) # input 받기 -> list 형태로
output = sorted(nums, reverse=True) # data를 내림차순으로 정렬


for i in range(len(output)): # 정렬된 data를 출력하기 위해서
    print(output[i], end = '') # 정렬된 data를 출력 

