I = []
al = [[] for _ in range(17)]
answer = 0

def dfs(now,sheep,wolf,edges):
    global al , answer , I

    #print("node: ",now, "-",sheep,wolf,edges)
    if I[now] == 0:
        sheep += 1
        answer = max(answer,sheep)
    else:
        wolf += 1
        
    if sheep <= wolf:
        return
    
    
    for edge in edges:
        next_edges = al[edge] + edges
        dfs(edge,sheep,wolf,[_ for _ in next_edges if _ != edge])
    return
        
def solution(info, edges):
    global I 
    global al, answer
    
    I = info
    
    for edge in edges:
        al[edge[0]].append(edge[1])
        
    dfs(0,0,0,al[0])
    
    return answer