import sys

# sys.stdin = open('BOJ/2606/example.txt')
input = sys.stdin.readline

N = int(input().rstrip())
M = int(input().rstrip())
graph = {}
visited = [0 for _ in range(N + 10)]
result = 0

for i in range(1, N + 1):
  graph[i] = []

for _ in range(M):
  a, b = map(int, input().rstrip().split())

  graph[a].append(b)
  graph[b].append(a)

def dfs(node):
  global result
  visited[node] = 1
  result += 1
  candidates = graph[node]

  for _, candidate in enumerate(candidates):
    if visited[candidate] == 0:
      dfs(candidate)

dfs(1)
print(result - 1)
