def order(t):
    global header, lst, n
    if t == 1 and header + 1 < n:  # 아래로 이동
        header += 1
    elif t == 2 and header - 1 >= 0:  # 위로 이동
        header -= 1
    elif t == 3 and header + 1 < n:  # 아래 원소와 swap 후 아래로 이동
        lst[header], lst[header + 1] = lst[header + 1], lst[header]
        header += 1
    elif t == 4 and header - 1 >= 0:  # 위 원소와 swap 후 위로 이동
        lst[header], lst[header - 1] = lst[header - 1], lst[header]
        header -= 1

n = int(input())  # 채널 개수
lst = [input() for _ in range(n)]  # 채널 목록
header = 0  # 현재 선택된 인덱스
answer = ""

# Step 1: "KBS1"을 맨 위로 이동
while lst[0] != "KBS1":
    index_kbs1 = lst.index("KBS1")
    while header < index_kbs1:  # "KBS1"을 찾아 내려감
        order(1)
        answer += "1"
    while header > 0:  # "KBS1"을 0번 인덱스로 올림
        order(4)
        answer += "4"

# Step 2: "KBS2"를 두 번째 위치로 이동
while lst[1] != "KBS2":
    index_kbs2 = lst.index("KBS2")
    while header < index_kbs2:  # "KBS2"를 찾아 내려감
        order(1)
        answer += "1"
    while header > 1:  # "KBS2"를 1번 인덱스로 올림
        order(4)
        answer += "4"

print(answer)
