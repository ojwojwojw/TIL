delta = [[0,1],[0,-1],[1,0],[-1,0]] 

### 함수 ###
def dfs(row,col):
    global visited, cnt, ans
    now = [-1,-1]
    next = [-1,-1]
    cnt_2 = 1

    stack = []
    stack.append([row,col]) ## stack 초기화
    visited[row][col] = True 

    while stack:
        now = stack.pop() 
        for d in delta: 
            next = [now[0] + d[0], now[1] + d[1]]
            if  next[0] >= 0 and  next[0] < N and next[1] >= 0 and next[1] < N and grid[next[0]][next[1]] != 0 and not visited[next[0]][next[1]]:
                visited[next[0]][next[1]] = True 
                stack.append([next[0],next[1]])
                cnt_2 += 1 
    
    ans.append(cnt_2)
    cnt += 1
    return
###########



### 입력부 ###
N = int(input()) 
grid = [list(map(int,input())) for _ in range(N)]
#############

### 변수 선언부 ###
visited = [[False]*N for _ in range(N)]

cnt = 0
ans = []
##################            

### 메인 로직 ###
for i in range(N):
    for j in range(N):
        if grid[i][j] != 0 and visited[i][j] == False :
            dfs(i,j) ## 함수 호출 
################


### 정답 출력 ###
print(cnt)
ans.sort()
for i in range(cnt):
    print(ans[i])
################



