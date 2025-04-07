import sys
sys.setrecursionlimit(111111)
input = sys.stdin.readline

# 0-1 냅색 문제 인데 무게가 0인 물건 존재
# dp[i][j] = max(dp[i-1][j],dp[i-1][j-c[i]]+A[i])

n, m = map(int, input().split())
A = list(map(int, input().split()))
c = list(map(int, input().split()))




dp = [[0]*(sum(c)+1) for _ in range(n+1)]
result = sum(c)
for i in range(1,n+1):
        byte = A[i-1]
        cost = c[i-1]
        for j in range(sum(c)+1):
            if j<cost:
                  dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-c[i-1]]+A[i-1])
            if dp[i][j]>=m:
                  result=min(result,j)

if m !=0:
      print(result)
else:
      print(0)
