def solution(n):
    answer = []
    
    
    ## 삼각형 구조의 2차원 배열 만들기 
    
    snail = [[0]*i for i in range(1,n+1)]
    ##print(snail)
    
    num = 0
    r,c = -1,0
    for i in range (n):
        for j in range(i, n):
            num += 1
            
            if i % 3 == 0 :
                r += 1
            elif i % 3 == 1 : 
                c += 1
            elif i % 3 == 2 : 
                r -= 1 
                c -= 1 
            
            snail[r][c] = num
    
    # for row in snail:
    #     for value in row:
    #         answer.append(value)
            
            
    for i in range(0,n):
        for j in range(0,i+1):
            answer.append(snail[i][j])

    ##print(snail)
    
    
    
    return answer