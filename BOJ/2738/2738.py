# 입출력 참고
# https://corin-e.tistory.com/entry/%EB%B0%B1%EC%A4%80-%EC%9E%85%EC%B6%9C%EB%A0%A5-%ED%8C%8C%EC%9D%B4%EC%8D%AC
import sys

sys.stdin = open("BOJ/2738/2738.txt", "r");

input = sys.stdin.readline

n, m = map(int, input().split())

board1 = [list(map(int, input().split())) for _ in range(n)]
board2 = [list(map(int, input().split())) for _ in range(n)]

result = [[0 for col in range(m)] for row in range(n)]

for i in range(n):
  for j in range(m):
    result[i][j] = board1[i][j] + board2[i][j]

for i in range(n):
  print(*result[i])