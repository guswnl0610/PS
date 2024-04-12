import sys

# sys.stdin = open('BOJ/2667/example.txt')
input = sys.stdin.readline

N = int(input().rstrip())
board = [[0] * N for _ in range(N)]
groupCount = 0
household = 0
households = []
dr = [-1, 1, 0, 0]
dc = [0, 0, -1, 1]

for i in range(N):
  board[i] = [int(char) for char in input().rstrip()]

def dfs(row, col):
  global household
  board[row][col] = 0
  household += 1

  for i in range(4):
    nr = row + dr[i]
    nc = col + dc[i]

    if 0 <= nr < N and 0 <= nc < N and board[nr][nc] == 1:
      dfs(nr, nc)

for i in range(N):
  for j in range(N):
    if board[i][j] == 1:
      groupCount += 1
      household = 0
      dfs(i,j)
      households.append(household)

print(groupCount)
households.sort()
for _, val in enumerate(households):
  print(val)
