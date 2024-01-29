def solution(edges):
    answer = [0]*4
    N = len(edges)
    in_line = [0]*2*N
    out_line = [0]*2*N

    for edge in edges:
        a,b = edge[0],edge[1]
        out_line[a] += 1
        in_line[b] += 1
    
    
    for edge in range(2*N):

        #나가는 간선은 두개이상이면서 들어오는 간선은 0개라면 추가된 정점
        if out_line[edge] >=2 and in_line[edge] == 0:
            answer[0] = edge
            M = out_line[edge]
        #들어오는 간선만 있는 정점은 막대그래프
        if out_line[edge] == 0 and in_line[edge] >= 1:
            answer[2] += 1
        #나가는 간선은 2개이면서 들어오는 간선이 2개이상라면 8자 그래프
        if out_line[edge] == 2 and in_line[edge] >= 2:
            answer[3] += 1
    #도넛그래프의 숫자는, 정점에서 나가는 간선수 M에서 나머지 그래프 숫자를 뺀 것
    answer[1] = M - answer[2] - answer[3]

    return answer