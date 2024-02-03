import sys

sys.stdin = open('BOJ/1032/example.txt', 'r')

input = sys.stdin.readline

n = int(input().rstrip())
files = [];

for i in range(n):
  files.append(input().rstrip())

fileNameLength = len(files[0])

result = '';

for i in range(fileNameLength):
  compareCharacter = files[0][i]
  hasSameCharacter = True

  for j in range(n):
    if compareCharacter != files[j][i]:
      hasSameCharacter = False

      break

  result = result + compareCharacter if hasSameCharacter else result + '?'

print(result)