def solution(record):
    answer = []
    userDb = {}
    command ,userId, userName = "","",""
    
    for row in record:
        lst = row.split()
        command =  lst[0] 
        userId  =  lst[1]
        if command in ["Enter","Change"] : 
            userName = lst[2]
            userDb[userId] = userName
        
    for row in record:
        lst = row.split()
        command =  lst[0] 
        userId  =  lst[1]
        userName = userDb[userId]

        if command == "Enter":
            answer.append(f"{userName}님이 들어왔습니다.")
        elif command == "Leave":
            answer.append(f"{userName}님이 나갔습니다.")
        
    
    
    return answer