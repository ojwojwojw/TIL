N,L = map(int, input().split())

halls = list(map(int, input().split()))
halls.sort()

start = 1
ans = 0
for hall in halls:
    if start <= hall:
        ans += 1
        start = hall + L
print(ans)