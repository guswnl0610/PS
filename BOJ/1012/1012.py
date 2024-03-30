import sys
# 이거안하면 RecursionError남
sys.setrecursionlimit(10**6)

# sys.stdin = open('BOJ/1012/example.txt')
input = sys.stdin.readline

T = int(input().rstrip())
board = []
dr = [-1, 1, 0, 0]
dc = [0, 0, -1, 1]
M = 0 # col
N = 0 # row
K = 0

def initialize():
  global board, result, M, N, K
  M, N, K = map(int, input().rstrip().split()) 

  board = [[0] * M for _ in range(N)]

  for _ in range(K):
    col, row = map(int, input().rstrip().split())
    board[row][col] = 1

def dfs(row, col):
  board[row][col] = 0

  for i in range(4):
    nextRow = row + dr[i]
    nextCol = col + dc[i]

    if nextRow >= 0 and nextRow < N and nextCol >= 0 and nextCol < M:
      if board[nextRow][nextCol] == 1:
        dfs(nextRow, nextCol)

def main():
  result = 0

  for r in range(N):
    for c in range(M):
      if board[r][c] == 1:
        dfs(r,c)
        result += 1
      
  print(result)

for _ in range(T):
  initialize()
  main()
