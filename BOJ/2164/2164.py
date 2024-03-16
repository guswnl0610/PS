import sys
from collections import deque

# sys.stdin = open('BOJ/2164/example.txt')

N = int(input())
q = deque()

for i in range(1, N + 1):
  q.append(i)

while(len(q) != 1):
  q.popleft()
  front = q.popleft()
  q.append(front)

print(q[0])