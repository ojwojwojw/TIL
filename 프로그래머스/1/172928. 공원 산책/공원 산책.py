dirMapping = { "E": (0,1),"W":(0,-1) ,"S":(1,0) ,"N":(-1,0)}


def solution(park, routes):
    answer = [-1,-1]
    nowI,nowJ = 0,0
    newI,newJ = 0,0
    maxI= len(park)
    maxJ = len(park[0])
    
    #현재 위치 찾기
    stop_search = False
    for i in range(maxI):
        for j in range(maxJ):
            if park[i][j] == "S":
                nowI = i 
                nowJ = j
                             
    skipOrder = False # 명령들을 스킵하기 위한 Boolean형 변수
    
    #명령들을 순회하며 하나씩 실행
    for i in range(len(routes)):
        skipOrder = False
        
        r1,r2 = routes[i].split()
        d = dirMapping[r1] #이동방향
        l = int(r2) # 이동거리
        #print(d,l)
        
        # '격자안에서' 장애물 X가 있는지 확인
        for i in range(1,l+1):
            newI = nowI + d[0]*i 
            newJ = nowJ + d[1]*i
            if (0 <= newI < maxI and 0 <= newJ < maxJ and park[newI][newJ] == 'X'):
                skipOrder = True
                break
        if skipOrder:
            continue
                
        # 장애물 X를 안만나고 격자 안에 있다면 이동
        newI = nowI + d[0]*l 
        newJ = nowJ + d[1]*l
        if not skipOrder and 0 <= newI < maxI and 0 <= newJ < maxJ:
            nowI = newI
            nowJ = newJ
    
    
    answer[0] = nowI
    answer[1] = nowJ
    
    return answer