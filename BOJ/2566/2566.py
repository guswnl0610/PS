import sys

sys.stdin = open("BOJ/2566/2566.txt", "r");

input = sys.stdin.readline

n = 9
board = [list(map(int, input().split())) for _ in range(n)]
max, resultRow, resultCol = -1, 0, 0

for i in range(n):
  for j in range(n):
    if max < board[i][j]:
      max = board[i][j]
      resultRow = i + 1
      resultCol = j + 1

print(max)
print(resultRow, resultCol)