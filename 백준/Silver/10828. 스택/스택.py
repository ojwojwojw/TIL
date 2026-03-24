N = int(input())
stack = []
orders = []

for i in range(N):
    s = list(input().split())
    orders.append(s)

for order in orders:
    if order[0] == "push":
        stack.append(order[1])

    elif order[0] == "pop":
        if len(stack) >= 1:
            a = stack.pop()
            print(a)
        else:
            print(-1)

    elif order[0] == "top":
        if len(stack) >= 1:
            print(stack[-1])
        else:
            print(-1)
            
    elif order[0] == "size":
        print(len(stack))

    elif order[0] == "empty":
        if len(stack) >= 1:
            print(0)
        else:
            print(1)