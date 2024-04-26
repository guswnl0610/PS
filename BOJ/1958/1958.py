import sys

# sys.stdin = open('BOJ/1958/example.txt')

strX = input()
strY = input()
strZ = input()

def getLCS():
  X = len(strX) + 1
  Y = len(strY) + 1
  Z = len(strZ) + 1

  matrix = [[[0 for _ in range(X)] for _ in range(Y)] for _ in range(Z)]

  for k in range(1, Z):
    for i in range(1, Y):
      for j in range(1, X):
        charX = strX[j-1]
        charY = strY[i-1]
        charZ = strZ[k-1]

        if charY == charX == charZ:
          matrix[k][i][j] = matrix[k-1][i-1][j-1] + 1
        else:
          matrix[k][i][j] = max(matrix[k][i-1][j], matrix[k][i][j-1], matrix[k-1][i][j])
  
  return matrix[Z-1][Y-1][X-1]

print(getLCS())