import sys

sys.stdin = open('BOJ/2979/example.txt')

input = sys.stdin.readline

A, B, C = map(int, input().split())

timelines = [0 for _ in range(110)]
fees = [0, A, B, C]

for _ in range(3):
  inTime, outTime = map(int, input().split())

  for i in range(outTime - inTime):
    timelines[i + inTime] = timelines[i + inTime] + 1
  
totalAmout = 0

for i, count in enumerate(timelines):
  if(count >= 0):
    totalAmout = totalAmout + fees[count] * count

print(totalAmout)