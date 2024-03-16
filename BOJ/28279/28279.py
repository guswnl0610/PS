import sys
from collections import deque

sys.stdin = open('BOJ/28279/example.txt')

input = sys.stdin.readline
N = int(input().rstrip())
q = deque()

for _ in range(N):
  commands = input().rstrip().split()
  command = commands[0]

  if command == '1':
    q.appendleft(commands[1])
  elif command == '2':
    q.append(commands[1])
  elif command == '3':
    if len(q) == 0:
      print(-1)
    else:
      front = q.popleft()
      print(front)
  elif command == '4':
    if len(q) == 0:
      print(-1)
    else:
      back = q.pop()
      print(back)
  elif command == '5':
    print(len(q))
  elif command == '6':
    print(1 if len(q) == 0 else 0)
  elif command == '7':
    print(-1 if len(q) == 0 else q[0])
  else:
    print(-1 if len(q) == 0 else q[-1])




# 1 X: 정수 X를 덱의 앞에 넣는다. (1 ≤ X ≤ 100,000)
# 2 X: 정수 X를 덱의 뒤에 넣는다. (1 ≤ X ≤ 100,000)
# 3: 덱에 정수가 있다면 맨 앞의 정수를 빼고 출력한다. 없다면 -1을 대신 출력한다.
# 4: 덱에 정수가 있다면 맨 뒤의 정수를 빼고 출력한다. 없다면 -1을 대신 출력한다.
# 5: 덱에 들어있는 정수의 개수를 출력한다.
# 6: 덱이 비어있으면 1, 아니면 0을 출력한다.
# 7: 덱에 정수가 있다면 맨 앞의 정수를 출력한다. 없다면 -1을 대신 출력한다.
# 8: 덱에 정수가 있다면 맨 뒤의 정수를 출력한다. 없다면 -1을 대신 출력한다.
