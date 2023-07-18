def com(k,begin):
    if k == M:
        print(*A)
        return
    else:
        for i in range(begin,1+N):
            A[k] = i
            com(k+1,i+1)


N,M = map(int,input().split())
A = [-1]*M
com(0,1)
