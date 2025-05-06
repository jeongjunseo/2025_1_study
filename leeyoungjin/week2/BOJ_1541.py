# list 순회하며 + 를 찾는다 -> 찾으면 i-2번 원소와 i + 2번 원소에 ( 집어넣기 ??
# - 를 기준으로 ()를 치면 가장 적은 값이 될 것이다 . 그러니까 split()으로 - 기준으로 값을 잘라서 리스트 슛
import sys

input_list = input().split('-') # -를 기준으로 리스트에 저장
output_list = [] # 연산 결과를 저장할 리스트 선언

for i in input_list: # 리스트 돌고
    sum = 0
    plus_array = i.split('+') # + 기준으로 리스트에 넣을거고
    for j in plus_array: 
        sum += (int(j)) # 리스트 원소를 int로 바꾸어서 더하기 연산
    output_list.append(sum) # 결과를 넣어줍시다

sum2 = output_list[0] # - 연산 실행할건데 -= 을 위해 초기값 set
for i in range(1,len(output_list)): 
    sum2 -= output_list[i] # - 연산 쭉쭉 ~~~

print(sum2) # 결과출력
