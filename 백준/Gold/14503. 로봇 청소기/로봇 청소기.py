import sys

N,M = map(int,sys.stdin.readline().split())
r,c,d = map(int,sys.stdin.readline().split()) 
# d는 0,1,2,3 순서대로 북동남서 

grid = [list(map(int,sys.stdin.readline().split())) for _ in range(N)]

dx = [-1 ,0 ,1 ,0] 
dy = [0 ,1 ,0 ,-1]   
ans = 0

while(1):
    # print("cnt: ",cnt)
    # print(r,c)
    # print(grid)
    # print("=====================================")

    ##현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
    if grid[r][c] == 0:
        grid[r][c] = 2
        ans +=1
    
    canGo = 0
    for i in range(4):
        newR = r + dx[i] 
        newC = c + dy[i]
        if(0 <= newR and newR < N and 0 <= newC and newC < M and grid[newR][newC] == 0):
            canGo += 1
            break

    ## 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우
    if canGo:
        ## 반시계 방향 회전  
        d -= 1
        if d < 0:
            d += 4

        ## 갈 수 있는 곳이면 한칸 전진 
        newR = r + dx[d] 
        newC = c + dy[d]
        if(0 <= newR and newR < N and 0 <= newC and newC < M and grid[newR][newC] == 0):
            r = newR
            c = newC
    ##현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
    else: 
        ##갈 수 있는 곳이면 한칸 후진
        newR = r - dx[d] 
        newC = c - dy[d]
        if(0 <= newR and newR < N and 0 <= newC and newC < M ):
            if(grid[newR][newC] == 2):
                r = newR
                c = newC
            elif(grid[newR][newC] == 1):
                ## 후진할 곳이 벽이면 작동을 멈춘다. 
                break
        
          
print(ans)
  