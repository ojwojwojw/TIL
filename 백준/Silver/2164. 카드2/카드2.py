from collections import deque

N = int(input())
lst = [ i for i in range(1,N+1)]
dq = deque(lst)
answer = 1

if(N != 1):
    while(True):
        dq.popleft()
        if (len(dq) == 1):
            break

        temp = dq.popleft()
        dq.append(temp)
        if (len(dq) == 1):
            break

    answer = dq[0]

print(answer)