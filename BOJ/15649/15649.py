import sys

# sys.stdin = open('BOJ/15649/example.txt')

N, M = map(int, input().split())
visited = [0 for _ in range(N + 10)]
result = 0

def dfs(arr):
  if len(arr) == M:
    print(*arr)
    return
  
  for i in range(1, N+1):
    if visited[i] == 0:
      visited[i] = 1
      dfs(arr + [i])
      visited[i] = 0

dfs([])