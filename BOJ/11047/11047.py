import sys
import math

# sys.stdin = open('BOJ/11047/example.txt')

N, K = map(int, input().split())
coins = [0 for _ in range(N)]

for i in range(N):
  coins[i] = int(input())

coins.sort(reverse=True)

result = 0

for i in range(N):
  if K >= coins[i]:
    coinCount = math.floor(K / coins[i])

    result = result + coinCount
    K = K - coinCount * coins[i]

print(result)
