import sys
from collections import deque

# sys.stdin = open('BOJ/18258/example.txt')

input = sys.stdin.readline
N = int(input().rstrip())
q = deque()

for _ in range(N):
  commands = input().rstrip().split()
  command = commands[0]

  if command == 'push':
    q.append(commands[1])
  elif command == 'pop':
    if len(q) == 0:
      print(-1)
    else:
      popped = q.popleft()
      print(popped)
  elif command == 'size':
    print(len(q))
  elif command == 'empty':
    if len(q) == 0:
      print(1)
    else:
      print(0)
  elif command == 'front':
    if len(q) == 0:
      print(-1)
    else:
      print(q[0])
  else:
    if len(q) == 0:
      print(-1)
    else:
      print(q[-1])

# push X: 정수 X를 큐에 넣는 연산이다.
# pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
# size: 큐에 들어있는 정수의 개수를 출력한다.
# empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
# front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
# back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.