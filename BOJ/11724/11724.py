import sys

# sys.stdin = open('BOJ/11724/example.txt')
input = sys.stdin.readline

N, M = map(int, input().rstrip().split())
graph = {}

visited = [0 for _ in range(N + 10)]
result = 0

def dfs(node):
  visited[node] = 1

  candidates = graph[node]

  for _, candidate in enumerate(candidates):
    if visited[candidate] == 1:
      continue
    
    dfs(candidate)


def main():
  global result

  for i in range(1, N + 1):
    graph[i] = []

  for _ in range(M):
    a, b = map(int, input().rstrip().split())
    graph[a].append(b)
    graph[b].append(a)
  
  for node in range(1, N + 1):
    if visited[node] == 0:
      result += 1
      dfs(node)
  
  print(result)

main()
