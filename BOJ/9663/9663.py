import sys

# sys.stdin = open('BOJ/9663/example.txt')

N = int(input())
visited = [0 for _ in range(20)]
dr = [-1, -1, 1, 1]
dc = [-1, 1, -1, 1]
result = 0;
board = [[0] * N for _ in range(N)]

# 대각선 범위 안에 겹치는 퀸이 있는지 체크
def isAvailable(candidateRow, candidateCol):
  for i in range(4):
    for j in range(1, N + 1):
      nr = candidateRow + dr[i] * j
      nc = candidateCol + dc[i] * j

      # 범위를 벗어남
      if nr < 0 or nr >= N or nc < 0 or nc >= N:
        break
      else:
        # 대각선에 있음
        if board[nr][nc] == 1:
          return False

  return True

def dfs(arr):
  if len(arr) == N:
    global result
    result += 1

    return
  
  for i in range(N):
    if visited[i] == 0 and isAvailable(len(arr), i):
      board[len(arr)][i] = 1
      visited[i] = 1
      dfs(arr + [i])
      visited[i] = 0
      board[len(arr)][i] = 0

dfs([])
print(result)