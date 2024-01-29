def isDuplicate(timeA,timeB):
    a = 60*int(timeA[1][0:2])+int(timeA[1][3:5])+10 
    b = 60*int(timeB[0][0:2])+int(timeB[0][3:5])
    if a <= b:
        return False
    else:
        return True
    
def solution(book_time):
    N = len(book_time)
    answer = 0
    rooms = [[] for _ in range(N)]
   

        
    book_time.sort()
    used = [False]*N
    for room in rooms:
        for i in range(len(book_time)):
            if(not used[i]):
                if(room):
                    last = room[-1]  
                M = len(room)
                if(M == 0 or not isDuplicate(last , book_time[i])):
                    room.append(book_time[i])
                    used[i]=True


    #print(rooms)
    for room in rooms:
        if room:
            answer += 1
    
    return answer