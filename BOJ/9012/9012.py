import sys

# sys.stdin = open('BOJ/9012/example.txt')

T = int(input())

def isVPS(str):
  stack = []

  for i in range(len(str)):
    char = str[i]

    if(char == '('):
      stack.append(1)
    else:
      if(len(stack) == 0):
        return False
      
      stack.pop()

  return len(stack) == 0


for _ in range(T):
  str = input()
  
  if(isVPS(str)):
    print('YES')
  else:
    print('NO')
