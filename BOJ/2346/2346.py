import sys
from collections import deque

# sys.stdin = open('BOJ/2346/example.txt')
input = sys.stdin.readline

N = int(input().rstrip())
balloons = list(map(int, input().rstrip().split()))
q = deque()
result = []

# [풍선번호, 종이] 튜플
for index, val in enumerate(balloons):
  q.append([index + 1, val])

while(len(q) != 1):
  balloonNumber, paper = q.popleft()
  result.append(balloonNumber)

  if paper >= 0:
    for _ in range(paper - 1):
      temp = q.popleft()
      q.append(temp)

  else:
    for _ in range(abs(paper)):
      temp = q.pop()
      q.appendleft(temp)

print(*result, q[0][0])
