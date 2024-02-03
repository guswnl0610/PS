import sys

sys.stdin = open("BOJ/2563/2563.txt", "r");

input = sys.stdin.readline

boardLength = 100;
paperLength = 10;
board = [[0 for col in range(boardLength)] for row in range(boardLength)]

paperCount = int(input().rstrip())

for k in range(paperCount):
  m, n = map(int, input().split())

  for i in range(paperLength):
    for j in range(paperLength):
      board[i + n][j + m] = 1

result = 0;

for i in range(boardLength):
  for j in range(boardLength):
    if(board[i][j] == 1):
      result = result + 1


print(result)
