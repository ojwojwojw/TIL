import sys

def dfs(r,c):
    global size
    local_size = 1  # 초기 셀을 계산
    ST = []
    n = 0
    ST.append((r,c,n))
    visited[r][c] = True
    while ST:
        r,c,n = ST.pop()

        for d in range(4):
            nr = r + dx[d]
            nc = c + dy[d]
            if 0<=nr<N and 0<=nc<M and not visited[nr][nc] and Grid[nr][nc] == '#':
                ST.append((nr,nc,n+1))
                visited[nr][nc] = True
                local_size += 1
    size = max(size, local_size)

input = sys.stdin.readline

dx = (1,0,-1,0)
dy = (0,1,0,-1)

N,M,K = map(int, input().split())
Grid = [['.']*M for _ in range(N)]
visited = [[False]*M for _ in range(N)]

for _ in range(K):
    r,c = map(int, input().split())
    Grid[r-1][c-1] = '#'

# print(Grid)

size = 0

for i in range(N):
    for j in range(M):
        if Grid[i][j] == '#' and not visited[i][j]:
            dfs(i,j)

print(size)