import sys
from collections import deque

# sys.stdin = open('BOJ/2636/example.txt')
input = sys.stdin.readline

N, M = map(int, input().rstrip().split())
board = [list(map(int, input().rstrip().split())) for _ in range(N)]
dr = [-1, 1, 0, 0]
dc = [0, 0, -1, 1]

def getRemainingCheese():
  cnt = 0

  for i in range(N):
    for j in range(M):
      if board[i][j] == 1:
        cnt += 1;

  return cnt

def bfs(start, visited, candidates):
  startRow, startCol = start
  visited[startRow][startCol] = 1

  q = deque()
  q.append(start)

  while len(q):
    row, col = q.popleft()

    for i in range(4):
      nr = row + dr[i]
      nc = col + dc[i]

      if 0 <= nr < N and 0 <= nc < M and visited[nr][nc] == 0:
        visited[nr][nc] = 1
        
        if board[nr][nc] == 0:
          q.append((nr, nc))
        # 이번에 녹는부분
        else:
          candidates.append((nr,nc))

def getCandidateMelted():
  visited = [[0] * M for _ in range(N)]
  candidates = []

  bfs((0, 0), visited, candidates)
  
  return candidates

def melt(candidates):
  for _, candidate in enumerate(candidates):
    row, col = candidate
    board[row][col] = 0

def main():
  hour = 0
  remainingCheese = getRemainingCheese()

  if remainingCheese == 0:
    print(hour)
    print(remainingCheese)

    return
  
  while True:
    hour += 1

    prevCheeseCount = getRemainingCheese()
    melt(getCandidateMelted())

    if getRemainingCheese() == 0:
      print(hour)
      print(prevCheeseCount)

      return

main()