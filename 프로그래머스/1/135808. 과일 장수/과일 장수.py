def solution(k, m, score):
    answer = 0
    score.sort(reverse = True)

    N = len(score)
    for i in range(m-1,N,m):
        answer += score[i]*m
    
    return answer