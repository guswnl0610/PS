import sys

# sys.stdin = open('BOJ/28278/example.txt')

input = sys.stdin.readline

N = int(input().rstrip())
stack = []

for _ in range(N):
  # command, x = input().split()
  command = input().rstrip()
  commandType = command[0]

  stackLength = len(stack)

  if(commandType == '1'):
    _, x = map(int, command.split())
    stack.append(x)

  elif(commandType == '2'):
    if(stackLength == 0):
      print('-1')
    else:
      print(stack[stackLength - 1])
      stack.pop()

  elif(commandType == '3'):
    print(stackLength)

  elif(commandType == '4'):
    if(stackLength > 0):
      print(0)
    else:
      print(1)

  else:
    if(stackLength == 0):
      print('-1')
    else:
      print(stack[stackLength - 1])

# 1 X: 정수 X를 스택에 넣는다. (1 ≤ X ≤ 100,000)
# 2: 스택에 정수가 있다면 맨 위의 정수를 빼고 출력한다. 없다면 -1을 대신 출력한다.
# 3: 스택에 들어있는 정수의 개수를 출력한다.
# 4: 스택이 비어있으면 1, 아니면 0을 출력한다.
# 5: 스택에 정수가 있다면 맨 위의 정수를 출력한다. 없다면 -1을 대신 출력한다.
