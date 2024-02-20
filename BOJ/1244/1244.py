import sys

sys.stdin = open('BOJ/1244/example.txt')

input = sys.stdin.readline

switchCount = int(input().rstrip())
switches = list(map(int, input().split())) # 스위치
N = int(input().rstrip()) # 학생수

def toggle(index):
  prevValue = switches[index]

  if(prevValue == 1):
    switches[index] = 0
  else:
    switches[index] = 1

def boy(number):
  toggle(number - 1)
  
  times = 2;
  nextIndex = number * times - 1
  
  while(nextIndex < switchCount):
    toggle(nextIndex)
    times = times + 1
    nextIndex = number * times - 1


def girl(number):
  startIndex = number - 1

  toggle(startIndex)

  diff = 1

  frontIndex = startIndex - diff
  backIndex = startIndex + diff

  while(frontIndex >= 0 and backIndex < switchCount):
    if(switches[frontIndex] == switches[backIndex]):
      toggle(frontIndex)
      toggle(backIndex)

      frontIndex = frontIndex - diff
      backIndex = backIndex + diff
    else:
      break


for _ in range(N):
  gender, number = map(int, input().split())

  if(gender == 1):
    boy(number)
  else:
    girl(number)

chunkSize = 20

for i in range(0, switchCount, chunkSize):
    chunk = switches[i:i+chunkSize]
    print(*chunk)
