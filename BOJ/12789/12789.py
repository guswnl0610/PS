import sys

# sys.stdin = open('BOJ/12789/example.txt')

N = int(input())
stack1 = list(map(int, input().split()))[::-1]
stack2 = []
currentOrder = 1;
  
while True:
  top1 = stack1[-1] if stack1 else -1
  top2 = stack2[-1] if stack2 else -1
  
  if top1 == currentOrder:
    currentOrder = currentOrder + 1
    stack1.pop()
  elif top2 == currentOrder:
    currentOrder = currentOrder + 1
    stack2.pop()
  else:
    if top1 == -1:
      break
    else:
      stack2.append(top1)
      stack1.pop()

if len(stack1) == 0 and len(stack2) == 0:
  print('Nice')
else:
  print('Sad')