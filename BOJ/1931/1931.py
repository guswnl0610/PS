import sys

# sys.stdin = open('BOJ/1931/example.txt')

N = int(input())
timelines = [() for _ in range(N)]

for i in range(N):
  start, end = map(int, input().split())
  timelines[i] = (start, end)
  
timelines.sort(key=lambda x: (x[1], x[0]))
currentTime = 0
result = 0

for _, timeline in enumerate(timelines):
  start, end = timeline

  if start >= currentTime:
    result = result + 1
    currentTime = end

print(result)