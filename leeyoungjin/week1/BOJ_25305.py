temp,cutline = map(int, input().split()) # 두개 받았음
 
nums = list(map(int, input().split()))[:temp]   # temp개 만큼의 정수 입력받음
output = sorted(nums, reverse=True) # data를 내림차순으로 정렬

print(output[cutline-1]) # cutline-1 번째 인덱스의 값을 출력

