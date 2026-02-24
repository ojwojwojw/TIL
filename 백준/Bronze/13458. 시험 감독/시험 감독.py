import sys 

N = int(sys.stdin.readline())
A =  list(map(int,sys.stdin.readline().split()))
B,C = map(int,sys.stdin.readline().split())

ans = 0
for i in range(N):
    remain = A[i] - B 
    ans += 1 
    if remain > 0 :
        ans += int(remain//C) 
        if remain % C != 0 :
            ans +=1 

print(ans)