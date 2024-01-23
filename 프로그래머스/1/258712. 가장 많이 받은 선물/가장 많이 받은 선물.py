def solution(friends, gifts):
    answer = 0
    N = len(friends)
    
    #친구 이름을 숫자로 매핑
    nameToNum = {}
    num = 0
    for friend in friends:
        nameToNum[friend] = num
        num += 1
        
    #선물을 주고받은 기록을 2차원 배열에 기록
    giftLog = [[0]*N for _ in range(N)]
    for gift in gifts:
        g,r = gift.split() 
        giver = nameToNum[g] # 숫자로 변환
        receiver = nameToNum[r]
        giftLog[giver][receiver] += 1
            
    #print(giftLogList)
    #선물 지수 기록
    giftPoint = [0]*N
    for giver in friends:
        g = nameToNum[giver]
        # g의 선물지수 계산
        g_point = sum(giftLog[g]) 
        d = 0
        for i in range(N):
            d += giftLog[i][g]
        g_point -= d
        giftPoint[g] = g_point
                
    
    
    ## 선물 기록을 바탕으로 선물 받을 횟수를 카운트
    giftCnt = [0]*N
    for giver in friends:
        for receiver in friends:
            g = nameToNum[giver]
            r = nameToNum[receiver]
            
            #두사람이 선물을 주고 받은 기록이 있다면
            if giftLog[g][r] or giftLog[r][g]:
                # 더 많이 준 쪽이 다음달 선물을 받아야 한다
                if  giftLog[g][r] > giftLog[r][g]:
                    #print(g,r,':',giftLog[g][r],giftLog[r][g])
                    
                    giftCnt[g] += 1
            #선물을 주고받은 기록이 없거나 수가 같다면
            if giftLog[g][r] == giftLog[r][g]:
                
                #선물 지수가 큰 쪽이 선물을 받아야 한다
                if giftPoint[g] > giftPoint[r]:
                    #print(g,r,':',giftPoint[g],giftPoint[r])
                    
                    giftCnt[g] += 1
                # 선물 지수도 같다면 아무 연산이 없다
                
            
    #print('giftLog:',giftLog)            
    #print('giftPoint:',giftPoint)
    #print('giftCnt:',giftCnt)
    
    answer = max(giftCnt)
    
    return answer