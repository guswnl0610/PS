import sys

# sys.stdin = open('BOJ/10799/example.txt')

#레이저는 L
str = input().replace('()', 'L')
stack = []
result = 0

for i in range(len(str)):
  char = str[i]

  if(char == '('):
    stack.append(1)
  elif(char == ')'):
    result = result + 1
    stack.pop()
  else:
    result = result + len(stack)  

print(result)