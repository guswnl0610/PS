# 입출력 참고
# https://corin-e.tistory.com/entry/%EB%B0%B1%EC%A4%80-%EC%9E%85%EC%B6%9C%EB%A0%A5-%ED%8C%8C%EC%9D%B4%EC%8D%AC
import sys

sys.stdin = open("BOJ/10798/10798.txt", "r");

input = sys.stdin.readline

n, m = 5, 15;


board = [['' for col in range(m)] for row in range(n)]

for i in range(n):
  string = input().rstrip()

  for j in range(len(string)):
    board[i][j] = string[j]

result = '';

for i in range(m):
  for j in range(n):
    result = result + board[j][i]

print(result)