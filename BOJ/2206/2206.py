import sys
from collections import deque

# sys.stdin = open('BOJ/2206/example.txt')
input = sys.stdin.readline

N, M = map(int, input().rstrip().split())
board = [[int(char) for char in input().rstrip()] for _ in range(N)]
dr = [-1, 1, 0, 0]
dc = [0, 0, -1, 1]

def main():
  visited = [[[0 for _ in range(M)] for _ in range(N)] for _ in range(2)]
  q = deque()
  q.append((0, 0, 1, 0))
  visited[0][0][0] = 1

  while len(q):
    r, c, depth, crashCount = q.popleft()

    if r == N-1 and c == M-1:
      return depth

    for i in range(4):
      nr = r + dr[i]
      nc = c + dc[i]
      
      if 0 <= nr < N and 0 <= nc < M:
        if board[nr][nc] == 0 and visited[crashCount][nr][nc] == 0:
          visited[crashCount][nr][nc] = 1
          q.append((nr, nc, depth+1, crashCount))
        elif board[nr][nc] == 1 and crashCount < 1:
          if visited[crashCount + 1][nr][nc] == 0:
            visited[crashCount + 1][nr][nc] = 1
            q.append((nr, nc, depth+1, crashCount+1))
  
  return -1

print(main())