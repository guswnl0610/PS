import sys

# sys.stdin = open('BOJ/1449/example.txt')

N, L = map(int, input().split())

holes = list(map(int, input().split()))
holes.sort()

result, lastIndex = 0, -1

for i in range(N):
  holeIndex = holes[i]
  
  if(lastIndex < holeIndex):

    result = result + 1
    lastIndex = holeIndex + L - 1
  
print(result)


