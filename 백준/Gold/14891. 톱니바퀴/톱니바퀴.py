# 톱니 바퀴를 회전 시키는 함수
def Rotate(G,R):
    # 시계방향으로 회전
    if R == 1:
        g1 = Gear[G][0:7]
        g2 = Gear[G][-1]
        Gear[G] = [g2] + g1
    # 시계 반대방향으로 회전
    if R == -1:
        g1 = Gear[G][1:8]
        g2 = Gear[G][0]
        Gear[G] =g1+[g2]


Gear = [[] for _ in range(5)]

# 톱니바퀴의 바퀴위치를 쉽게 찾기위한 변수선언
t = 0
r = 2
b = 4
l = 6

# 입력(명령)의 종류를 쉽게 알기 위한 변수선언
G = 0 # 톱니바퀴의 번호
R = 0 # 회전 방향

# 톱니바퀴 정보 입력받기
for i in range(1,5):
    Gear[i] = list(map(int,input()))
#print('init: ',Gear)

# 회전명령을 하나씩 순회하는 for문
for i in range(int(input())):
    order = list(map(int,input().split()))
    Q = []
    Q.append((order[0],order[1],-1))

    # R이1은 시계방향 -1 은 시계반대 방향
    ## 1번 톱니바퀴
    before = -1 #어떤 톱니바퀴에 의해 연쇄 회전이 일어나게 됐는지 기록해야한다
    while Q:
        now = Q.pop(0)
        G,R = now[0] ,now[1]
        before = now[2]
        #print (G,R)
        if G == 1 :
            #1번톱니와 2번톱니의 맞닿은 극이 다를때
            if (Gear[1][r] != Gear[2][l]) and before != 2:
                Q.append((2, -R , 1))


            Rotate(G, R)

        ## 2번 톱니바퀴
        if G == 2 :
            # 2번톱니와 1번톱니의 맞닿은 극이 다를때
            if (Gear[2][l] != Gear[1][r]) and before != 1:
                Q.append((1, -R, 2))


            # 2번톱니와 3번톱니의 맞닿은 극이 다를때
            if (Gear[2][r] != Gear[3][l]) and before != 3:
                Q.append((3, -R, 2))


            Rotate(G, R)

        ## 3번 톱니바퀴
        if G == 3 :
            # 3번톱니와 2번톱니의 맞닿은 극이 다를때
            if (Gear[3][l] != Gear[2][r]) and before != 2:
                Q.append((2, -R, 3))


            # 2번톱니와 3번톱니의 맞닿은 극이 같을때
            if (Gear[3][r] != Gear[4][l]) and before != 4:
                Q.append((4, -R, 3))


            Rotate(G, R)


        ## 4번 톱니바퀴
        if G == 4 :
            #4번톱니와 3번 톱니의 맞닿은 극이 다를때
            if (Gear[4][l] != Gear[3][r]) and before != 3:
                Q.append((3, -R, 4))


            Rotate(G, R)

        #print(Gear)
# 점수 계산하기
ans = 0
if Gear[1][t] == 1 :
    ans += 1
if Gear[2][t] == 1 :
    ans += 2
if Gear[3][t] == 1 :
    ans += 4
if Gear[4][t] == 1 :
    ans += 8

print(ans)