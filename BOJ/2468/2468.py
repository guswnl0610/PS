import sys
from collections import deque

# sys.stdin = open('BOJ/2468/example.txt')
input = sys.stdin.readline

N = int(input().rstrip())
matrix = [list(map(int, input().rstrip().split())) for _ in range(N)]
dr = [-1, 1, 0, 0]
dc = [0, 0, -1, 1]

def bfs(startRow, startCol, visited, depth):
  q = deque()
  q.append([startRow, startCol])
  visited[startRow][startCol] = 1

  while(len(q)):
    row, col = q.popleft()
    
    for i in range(4):
      nr = row + dr[i]
      nc = col + dc[i]

      if 0 <= nr < N and 0 <= nc < N and matrix[nr][nc] > depth and visited[nr][nc] == 0:
        visited[nr][nc] = 1
        q.append([nr, nc])

def getSafetyAreaCount(depth):
  areaCount = 0
  visited = [[0] * N for _ in range(N)]

  for i in range(N):
    for j in range(N):
      if matrix[i][j] > depth and visited[i][j] == 0:
        bfs(i,j,visited,depth)
        areaCount += 1
      
  return areaCount

def main():
  valueMap = {}
  depths = [0]
  
  for i in range(N):
    for j in range(N):
      if valueMap.get(matrix[i][j], False) == False:
        valueMap[matrix[i][j]] = 1
        depths.append(matrix[i][j])
        
  result = 0
  
  for _, depth in enumerate(depths):
    result = max(getSafetyAreaCount(depth), result)

  print(result)
  
main()