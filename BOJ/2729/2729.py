import sys

sys.stdin = open('BOJ/2729/example.txt')

input = sys.stdin.readline

T = int(input().rstrip())

for _ in range(T):
  A, B = input().split()

  print(format(int(A, 2) + int(B, 2), 'b'))