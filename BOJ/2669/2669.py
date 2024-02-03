import sys

sys.stdin = open('BOJ/2669/example.txt', 'r')

input = sys.stdin.readline

recCount = 4

board = [[0 for col in range(110)] for row in range(110)]

for _ in range(recCount):
  x1, y1, x2, y2 = map(int, input().rstrip().split())

  for r in range(abs(y1 - y2)):
    for c in range(abs(x1 - x2)):
      board[r + min(y1, y2)][c + min(x1, x2)] = 1

result = 0

for r in range(110):
  for c in range(110):
    if board[r][c] == 1:
      result = result + 1

print(result)
