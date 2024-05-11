import sys
from queue import PriorityQueue

# sys.stdin = open('BOJ/11279/example.txt')
input = sys.stdin.readline

N = int(input().rstrip())
pq = PriorityQueue()

for i in range(N):
  x = int(input().rstrip())

  if x == 0:
    if pq.empty():
      print(0)
    else:
      print(pq.get() * -1)
  else:
    pq.put(x * -1)
