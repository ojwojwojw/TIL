# 1 여러가지 구현 방법
```
V = 7+1
# E =
S = '1 2 1 3 2 4 2 5 4 6 5 6 6 7 3 7'
S =  list(map(int , S.split()))
G =[[]for _ in range(V)]

for idx in range(0, len(S) ,2 ):
    v1 = S[idx]
    v2 = S[idx+1]
    G[v1].append(v2)
    G[v2].append(v1)

print(G)


G = [[],[2,3],[1,4,5],[1,7],[2,6],[2,6],[4,5,7],[3,6]]
def dfs(v):
    ans_lst = []
    ST = []
    visited = [False]*V         # [ False,False,False,False,False,False,False,False]

    ST.append(v)
    visited[v] = True
    print(v)
    while ST :  #len(ST) > 0
        for w in G[v]:
            if not visited[w]:
                visited[w] = True
                print(w)
                ST.append(v)
                v = w
                break
        else:
            v = ST.pop()
    return ans_lst


# def dfs(v):
#     ST =[]
#     visited = [False]*V
#
#     ST.append(v)
#     while ST:
#         v= ST.pop()
#         if not visited[v]:
#             visited[v] = True
#             print(v)
#
#         for w in G[v]:
#             if not visited[w]:
#                 ST.append(w)
# #
# def dfs(v):
#     ST = []
#     visited = [False]*V
#
#     ST.append(v)
#     visited[v] = True
#     while ST:
#         v= ST.pop()
#         print(v)
#         for w in G[v]:
#             if not visited[w]:
#                 ST.append(w)
#                 visited[w] = True
#
# # visited = [False]*V
# # def dfsr(v):
# #     print(v)
# #     visited[v] = True
# #     for w in G[v]:
# #         if not visited[w]:
# #             dfsr(w)

print(dfs(1))
# dfsr(1)

```

# 2 순열로 간선 관리
```
V = 7+1
# E =
S = '1 2 1 3 2 4 2 5 4 6 5 6 6 7 3 7'
S =  list(map(int , S.split()))

G = [[0]*V for _ in range(V)]

for idx in range(0,len(S),2):
    v1 = S[idx]
    v2 = S[idx+1]
    G[v1][v2] +=1
    G[v2][v1] +=1

def dfs(v):
    ST = []
    visited = [False] * V

    ST.append(v)
    visited[v] = True
    while ST:
        v = ST.pop()
        print(v)
        #for w in G[v]:
        for w in range(V):
            if G[v][w] and not visited[w]:
                ST.append(w)
                visited[w] = True
dfs(1)



# G = [[],[2,3],[1,4,5],[1,7],[2,6],[2,6],[4,5,7],[3,6]]

```
