def solution(s):
    answer = 0
    
    cnt1 = 0
    cnt2 = 0
    isCounting = False
    x = ''
    
    for i in range(len(s)):
        if not isCounting:
            x = s[i]
            cnt1 = 0
            cnt2 = 0
        
        isCounting = True
        
        if s[i] == x:
            cnt1 += 1
        if s[i] != x:
            cnt2 += 1
        
        
        if cnt1 == cnt2:
            answer += 1
            isCounting = False
        
        if i == len(s)-1 and isCounting:
            answer += 1
        
        
    
    return answer