Visited = [(0,False)]*100001

StartLocation ,BrotherLocation, = map(int, input().split())
Q = []
Q.append(StartLocation)
Visited[StartLocation] = ('start',False)
while Q:
    v = Q.pop(0)
    for w in [v+1,v-1,2*v]:
        if  0 <= w <= 100000 and not Visited[w][1]:
            Q.append(w)
            Visited[w] =(v ,Visited[v][1] + 1)
            if w == BrotherLocation:
                findpoint = w
                break
    if w == BrotherLocation:
        break

ans1= Visited[findpoint]

# print(Visited)
if StartLocation == BrotherLocation:
    print(0)
    print(StartLocation)
else:

    print(ans1[1])

    ans2 = [BrotherLocation]
    num = BrotherLocation
    while len(ans2) != ans1[1]+1:
        for idx in range(0,len(Visited)):
            if idx == num:
                ans2.append(Visited[idx][0])
                num = Visited[idx][0]
                break
    ans2 = ans2[len(ans2)::-1]
    print(*ans2)