N,M = map(int,(input().split()))
hash = {}
for i in range(M):
    hash[str(input())] = i

sorted_hash = sorted(hash.items(), key = lambda x : x[1])

for i in range(N):
    if (i < len(sorted_hash)):
        print(sorted_hash[i][0])
    else:
        break
