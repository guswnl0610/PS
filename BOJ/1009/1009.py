import sys

sys.stdin = open('BOJ/1009/example.txt')

input = sys.stdin.readline

T = int(input().rstrip())

modularMap = {
  0: [10],
  1: [1],
  2: [2,4,8,6],
  3: [3,9,7,1],
  4: [4,6],
  5: [5],
  6: [6],
  7: [7,9,3,1],
  8: [8,4,2,6],
  9: [9,1]
}

for _ in range(T):
  a, b = map(int, input().split())

  modulars = modularMap[a % 10]
  modLength = len(modulars)
  
  if(modLength == 1):
    print(modulars[0])

    continue

  modIndex = (b - 1) % modLength

  print(modulars[modIndex])