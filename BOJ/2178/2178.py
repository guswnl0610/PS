import sys
from collections import deque

# sys.stdin = open('BOJ/2178/example.txt')

N, M = map(int, input().split())
maze = [[0] * M for _ in range(N)]
dr = [-1, 1, 0, 0]
dc = [0, 0, -1, 1]
q = deque()

for row in range(N):
  maze[row] = [int(char) for char in input()]

def bfs():
  maze[0][0] = 0
  q.append((0, 0, 1))
  

  while len(q):
    row, col, depth = q.popleft()

    if row == N-1 and col == M-1:
      return depth

    for i in range(4):
      nr = row + dr[i]
      nc = col + dc[i]

      if 0 <= nr < N and 0 <= nc < M and maze[nr][nc] == 1:
        maze[nr][nc] = 0
        q.append((nr, nc, depth + 1))
    
print(bfs())
