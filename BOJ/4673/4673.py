maxNum = 10000
constructorMap = [0 for _ in range(maxNum + 10)]

def d(num):
  return num + sum([int(i) for i in str(num)])

for i in range(maxNum):
  number = i + 1

  dValue = d(number)

  if dValue <= maxNum:
    constructorMap[dValue] = 1


for i in range(maxNum):
  if constructorMap[i + 1] == 0:
    print(i + 1)
