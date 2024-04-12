import sys

sys.setrecursionlimit(10 ** 5)
# sys.stdin = open('BOJ/4963/example.txt')
input = sys.stdin.readline

board = []
result = 0
N = 0
M = 0
dr = [-1, -1, -1, 0, 0, 1, 1, 1] # 8방향
dc = [-1, 0, 1, -1, 1, -1, 0, 1]

def dfs(row, col):
  board[row][col] = 0

  for i in range(8):
    nr = row + dr[i]
    nc = col + dc[i]

    if 0 <= nr < N and 0 <= nc < M and board[nr][nc] == 1:
      dfs(nr, nc)

while True:
  M, N = map(int, input().rstrip().split())
  result = 0

  if M == 0 and N == 0: 
    break

  board = [[0] * M for _ in range(N)]

  for i in range(N):
    board[i] = list(map(int, input().rstrip().split()))
                 
  for i in range(N):
    for j in range(M):
      if board[i][j] == 1:
        result += 1
        dfs(i,j)
  
  print(result)