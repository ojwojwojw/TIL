from collections import deque

delta = [(1,0),(0,1),(-1,0),(0,-1)]

def solution(land):
    answer = 0
    
    #bfs
    maxI = len(land)
    maxJ = len(land[0])
    #print(visited)
    
    report = [0]*maxJ
    #모든 좌표들을 순회하며 bfs 한다
    for i in range(maxI):
        
        for j in range(maxJ):
            # bfs 탐색 전 초기화 해야하는 변수
            oil = 1
            minY = 501
            maxY = -1


            # 방문한 점이 아니고, 석유가 있다면 dfs 한다
            if land[i][j] == 1:   
                # 일단 스택에 현재탐색지점을 집어넣는다
                Q = deque()
                nowLand = [i,j]
                land[i][j] = 0
                Q.append(nowLand)
                while Q:
                    # 스택에서 탐색지점을 하나 pop하고, 가로좌표의 최솟값 최댓값을 기록한다 
                    nowLand = Q.popleft()
                    if nowLand[1] >= maxY:
                        maxY = nowLand[1]
                    if nowLand[1] <= minY:
                        minY = nowLand[1]
                    
                    for d in delta:
                        newLand = [nowLand[0] + d[0],nowLand[1] + d[1]]
                        if 0<=newLand[0]<maxI and 0<=newLand[1]<maxJ and land[newLand[0]][newLand[1]] == 1:
                            Q.append(newLand)
                            land[newLand[0]][newLand[1]] = 0
                            # 석유지가 몇개 있었는지 oil 변수로 기록한다
                            oil+=1
                    
                #bfs의 마지막에 report에 기록한다
                #print(minY,maxY+1)
                for l in range(minY,maxY+1):
                    report[l] += oil
                    

    #report 확인용
    #print(report)
    
    
        

    return max(report)        
        
        
                
            
                            
                        
                
                