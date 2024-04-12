import sys
from collections import deque

# sys.stdin = open('BOJ/1260/example.txt')

input = sys.stdin.readline

N, M, V = map(int, input().rstrip().split())
graph = {}
queue = deque()
visited = [0 for _ in range(N + 10)]

for i in range(1, N+1):
  graph[i] = []

for _ in range(M):
  a, b = map(int, input().rstrip().split())
  
  graph[a] = graph[a] + [b]
  graph[b] = graph[b] + [a]

for i in range(1, N+1):
  graph[i].sort()

def dfs(node):
  visited[node] = 1
  print(node, end=' ')

  if len(graph[node]) == 0:
    return 

  for _, next in enumerate(graph[node]):
    if visited[next] == 0:
      dfs(next)
  
def bfs(node):
  global bfsResult

  visited = [0 for _ in range(N + 10)]
  visited[node] = 1
  queue.append(node)
  print(node, end=' ')

  while len(queue) > 0:
    front = queue.popleft()
    
    for _, next in enumerate(graph[front]):
      if visited[next] == 0:
        visited[next] = 1
        queue.append(next)
        print(next, end=' ')

dfs(V)
print(end='\n')
bfs(V)
print(end='\n')