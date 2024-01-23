def solution(board, moves):
    answer = 0
    ST = [] #바구니
    N = len(board[0])
    
    #인형을 뺀다.
    for move in moves:
        for depth in range(N):
            if(board[depth][move-1]):
                doll=board[depth][move-1] #인형의 번호
                ST.append(doll)  #바구니에 넣는다
                if(len(ST)>=2 and ST[-2] == doll):  #하나 넣을때마다 터지는게 있나 검사를 한다.
                    ST.pop()
                    ST.pop()
                    answer += 2
                board[depth][move-1] = 0  #보드의 인형이 있던 자리를 0으로 바꾼다
                break
            
    
    return answer