import sys

# sys.stdin = open('BOJ/9251/example.txt')

strX = input()
strY = input()

def getLCS():
  X = len(strX) + 1;
  Y = len(strY) + 1
  matrix = [[0 for _ in range(X)] for _ in range(Y)]

  for i in range(1, Y):
    for j in range(1, X):

      charX = strX[j-1]
      charY = strY[i-1]

      if charY == charX:
        matrix[i][j] = matrix[i-1][j-1] + 1
      else:
        matrix[i][j] = max(matrix[i-1][j], matrix[i][j-1])
  
  return matrix[Y-1][X-1]

print(getLCS())