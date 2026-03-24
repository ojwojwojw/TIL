N = int(input())

lst = list(map(int,input().split()))


##print(lst)

lst.sort()

##print(lst)

for i in range(N):
    if i >=1:
        lst[i] = lst[i] + lst[i-1]

print(sum(lst))