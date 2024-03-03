import sys

# sys.stdin = open('BOJ/10870/example.txt')

def dp(number):
  fibonaccis = [0 for _ in range(25)]
  fibonaccis[1] = 1

  for i in range(2, number + 1):
    fibonaccis[i] = fibonaccis[i-1] + fibonaccis[i-2]

  return fibonaccis[number]


def recursion(number):
  if(number == 0 or number == 1):
    return number
  
  return recursion(number - 1) + recursion(number - 2)


def main():
  n = int(input())

  if(n == 0 or n == 1):
    print(n)
    
    return
  
  print(dp(n))
  print(recursion(n))

main()