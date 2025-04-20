import sys

temp = int(sys.stdin.readline().strip()) # 문자 한 줄 입력받기 => input보다 실행 속도 빠름

array = list(map(int, sys.stdin.readline().strip().split()))[:temp] # 압축할 좌표 입력받기 / strip = 공백 제거 

array_sort = sorted(list(set(array))) # 받은 숫자 정렬 이후 새로운 list에 저장장

dic = {} # dictionary 생성 -> 중복 제거 이후 크기 순서대로 배열하여 index와 original 값을 넣어줄 계획
for i in range(len(array_sort)):
  dic[array_sort[i]] = i # 순서를 dic에 넣어줌


for i in array:
  print(dic[i], end=" ") # 원래의 숫자에 대해 dic에서 index를 찾아서 출력

