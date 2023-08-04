def per(k,begin):
    if k == M:
        print(*A)
        return
    else:
        for i in range(begin,1+N):
            A[k] = i
            per(k+1,i)

N,M = map(int, input().split())
A = [-1]*M
per(0,1)