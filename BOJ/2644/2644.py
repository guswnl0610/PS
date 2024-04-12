import sys
from collections import deque

# sys.stdin = open('BOJ/2644/example.txt')

input = sys.stdin.readline

N = int(input().rstrip())
A, B = map(int, input().rstrip().split())
M = int(input().rstrip())
visited = [0 for _ in range(N + 10)]
graph = {key: [] for key in range(N + 1)}
queue = deque()

def bfs():
  visited[A] = 1
  queue.append((A, 0))

  while len(queue):
    front, depth = queue.popleft()

    if front == B:
      return depth

    for _, next in enumerate(graph[front]):
      if visited[next] == 0:
        visited[next] = 1
        queue.append((next, depth + 1))
  
  return -1

def main():
  for _ in range(M):
    a, b = map(int, input().rstrip().split())
    graph[a] = graph[a] + [b]
    graph[b] = graph[b] + [a]

  print(bfs())
  
main()