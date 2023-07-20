def dfs():
    v = 1
    ST = []
    ST.append(v)
    Visited[v] = True
    while ST:
        v = ST.pop()
        for w in Graph[v]:
            if not Visited[w]:
                ST.append(w)
                Visited[w] = True

numOfComputer = int(input())
numOfLine = int(input())
Graph = [[] for i in range (numOfComputer+1)]
Visited = [False] * (numOfComputer + 1)

for i in range(numOfLine):
    a,b = map(int, input().split())
    Graph[a].append(b)
    Graph[b].append(a)

dfs()

# print(Graph)
ans = 0
for bool in Visited:
    if bool == True:
        ans +=1

print(ans-1)


