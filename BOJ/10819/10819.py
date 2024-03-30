import sys

# sys.stdin = open('BOJ/10819/example.txt')

N = int(input())
numbers = list(map(int, input().split()))
numbers = [x + 100 for x in numbers]
visited = [0 for _ in range(10)]
result = 0;

def getSum(arr):
  sum = 0

  for i in range(0, len(arr) - 1):
    sum += abs(arr[i] - arr[i+1])
  
  return sum

def dfs(arr):
  if len(arr) == N:
    sum = getSum(arr)
    global result

    if sum > result:
      result = sum

    return
  
  for i, num in enumerate(numbers):
    if visited[i] == 0:
      visited[i] = 1
      dfs(arr + [num])
      visited[i] = 0
  
dfs([])
print(result)
