def solution(left, right):
    answer = 0
    
    for num in range(left,right+1):
        d = 1
        cnt = 0
        while(d**2<=num):
            if d**2 == num:
                cnt += 1
            if num%d == 0:
                cnt += 2
            d += 1
        if cnt%2:
            answer -= num
        else:
            answer += num
            
    
    return answer