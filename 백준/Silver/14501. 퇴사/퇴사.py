import sys
input = sys.stdin.readline

if __name__ == "__main__":
    N = int(input())
    arr = []
    arr.append(())
    for i in range(N):
        t, p = map(int,input().split())
        arr.append((t, p))

    dp = [0 for _ in range(N+1)]

    for i in range(N,0,-1):
        temp = i + arr[i][0]
        if i == N:
            if arr[i][0] == 1:
                dp[i] = arr[i][1]
        elif temp == N + 1:
            dp[i] = max(arr[i][1], dp[i + 1])
        elif temp < N + 1:
            dp[i] = max(arr[i][1] + dp[temp], dp[i + 1])
        else:
            dp[i] = dp[i+1]
    print(dp[1])