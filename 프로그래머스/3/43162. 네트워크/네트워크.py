def solution(n, computers):
    answer = 0
    
    visited = [False] * n

    for i in range(n):
        if not visited[i]:
            stack = [i]
            visited[i]= True
                
            while stack:
                current = stack.pop()
                
                for d in range(n):
                    if not visited[d] and computers[current][d]:
                        visited[d] = True
                        stack.append(d)
                        
            answer += 1
            
            

    
    
    
    return answer