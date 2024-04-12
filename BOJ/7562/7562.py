import sys
from collections import deque

# sys.stdin = open('BOJ/7562/example.txt')
input = sys.stdin.readline
T = int(input().rstrip())
visited = [[0] * 310 for _ in range(310)]
dr = [-1, -2, -2, -1, 1, 2, 2, 1]
dc = [-2, -1, 1, 2, -2, -1, 1, 2]

def bfs(start, destination, boardSize):
  startRow, startCol = start
  destRow, destCol = destination

  visited[startRow][startCol] = 1

  q = deque()
  q.append((startRow, startCol, 0))

  while len(q):
    row, col, depth = q.popleft()

    if row == destRow and col == destCol:
      return depth
    
    for i in range(8):
      nr = row + dr[i]
      nc = col + dc[i]

      if 0 <= nr < boardSize and 0 <= nc < boardSize and visited[nr][nc] == 0:
        visited[nr][nc] = 1
        q.append((nr, nc, depth + 1))

def main():
  global visited

  for _ in range(T):
    N = int(input().rstrip())
    visited = [[0] * 310 for _ in range(310)]
    startRow, startCol = map(int, input().rstrip().split())
    destRow, destCol = map(int, input().rstrip().split())

    print(bfs((startRow, startCol), (destRow, destCol), N))

main()
