import sys

# sys.stdin = open('BOJ/9252/example.txt')

strX = input()
strY = input()

def getLCSMatrix():
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
  
  return matrix

def getLCSString(matrix):
  lcs = []
  curY = len(strY)
  curX = len(strX)

  while len(lcs) != matrix[len(strY)][len(strX)]:
    cur = matrix[curY][curX]
    up = matrix[curY-1][curX]
    left = matrix[curY][curX-1]

    if cur == up:
      curY -= 1
    elif cur == left:
      curX -= 1
    else:
      lcs.append(strX[curX-1])
      curY -= 1 
      curX -= 1
  
  return "".join(lcs[::-1])

matrix = getLCSMatrix()
lcsCount = matrix[len(strY)][len(strX)]
print(lcsCount)

if lcsCount > 0:
  print(getLCSString(matrix))
