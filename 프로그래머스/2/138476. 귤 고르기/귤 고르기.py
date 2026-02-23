def solution(k, tangerine):
    answer = 1
    
    dict = {}
    for num in tangerine:
        dict[num] = dict.get(num,0) + 1
        
    sortedDict = sorted(dict.items(), key = lambda x : x[1] , reverse= True )

    ##print (sortedDict)

    cnt = 0
    for item in sortedDict:
        cnt += item[1]
        if cnt < k : 
            answer +=1 
        else :
             return answer
        
    
    
   