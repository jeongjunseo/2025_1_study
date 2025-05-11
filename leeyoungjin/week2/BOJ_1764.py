# 듣보잡
import sys
input = sys.stdin.readline

listen, see = map(int, input().split()) # 변수 선언하고 input 형태로 받는다
 
listen_set = set() # set 형태로 선언 / 중복 제거 되고 sorted해서 정렬하기 좋으니까 
see_set = set() 

for _ in range(listen): # listen의 개수만큼 set에 add
    listen_set.add(input().strip())

for _ in range(see): # see의 개수만큼 set에 add
    see_set.add(input().strip())

compare = sorted(list(listen_set & see_set))  # 각 set의 교집합을 list에 넣고 사전순 정렬
count = len(compare) # compare의 길이 = 중복 사람 수니까 COUNT로 선언
 
print(count) # 카운트 출력
for i in compare: # compare list에서 하나씩 출력
    print(i)








