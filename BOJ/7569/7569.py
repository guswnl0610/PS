import sys
from collections import deque

# sys.stdin = open('BOJ/7569/example.txt')
input = sys.stdin.readline

M, N, H = map(int, input().rstrip().split())
# board[h][r][c]
board = [[list(map(int, input().rstrip().split())) for _ in range(N)] for _ in range(H)]
dr = [-1, 1, 0, 0, 0, 0]
dc = [0, 0, -1, 1, 0, 0]
dh = [0, 0, 0, 0, -1, 1]
    
def ripeTomatoes(visited):
  q = deque()

  for k in range(H):
    for i in range(N):
      for j in range(M):
        if board[k][i][j] == 1:
          visited[k][i][j] = 1
          q.append((k, i, j, 0))
  
  while len(q):
    h, r, c, depth = q.popleft()

    for i in range(6):
      nr = r + dr[i]
      nc = c + dc[i]
      nh = h + dh[i]

      if 0 <= nr < N and 0 <= nc < M and 0 <= nh < H and visited[nh][nr][nc] == 0 and board[nh][nr][nc] == 0:
        board[nh][nr][nc] = depth + 1
        q.append((nh, nr, nc, depth + 1))

def isAllRipedTomatoes():
  for k in range(H):
    for i in range(N):
      for j in range(M):
        if board[k][i][j] == 0:
          return False
        
  return True

def main():
  if isAllRipedTomatoes():
    print(0)

    return
  
  visited = [[[0] * M for _ in range(N)] for _ in range(H)]
  ripeTomatoes(visited)

  result = 0
  for k in range(H):
    for i in range(N):
      for j in range(M):
        result = max(result, board[k][i][j])

        if visited[k][i][j] == 0 and board[k][i][j] == 0:
          print(-1)

          return
        
  print(result)

main()