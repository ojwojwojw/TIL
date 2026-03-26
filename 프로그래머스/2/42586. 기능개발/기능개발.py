
def solution(progresses, speeds):
    answer = []
    isEnd = False
    RealseYnList = [False]*len(progresses)    
        
    while not isEnd :
        ##checkEnd
        isEnd = True
        for progress in progresses:
            if progress != 100:
                isEnd = False
        
        ##add
        for i in range(len(progresses)):
            progresses[i] += speeds[i]
                
        for i in range(len(progresses)):
            if  progresses[i] > 100:
                progresses[i] = 100
                
        print("progresses:", progresses)       
                    
        ##checkDevFin
        devFin = []
        for i in range(len(progresses)):
            if progresses[i] == 100:
                devFin.append(i)

        print("devFin: ", devFin)     
                
        ##Realse
        if devFin:
            print("!!!start Realse!!!")

            while devFin:
                ##deep Copy devFin to rIdx
                rIdx = []
                for d in devFin:
                    rIdx.append(d)
                
                finIdx = devFin.pop()
                
                
                
                canRealse = True
                cnt = 0
                
                for i in range(finIdx,-1,-1):
                    if progresses[i] != 100:
                        cnt = 0
                        canRealse = False
                        break
                    
                    if progresses[i] == 100 and not RealseYnList[i]:
                        cnt +=1
                        
                if canRealse and cnt != 0 :
                    for r in rIdx:
                        RealseYnList[r] = True
                    
                    answer.append(cnt)
                 
            
        
    
    return answer