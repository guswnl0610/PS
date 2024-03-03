import sys;

sys.stdin = open('BOJ/10872/example.txt')

input = sys.stdin.readline

# dp
def dp(target):
  factorials = [1 for _ in range(510)];
  
  for i in range(2, target + 1):
    factorials[i] = factorials[i-1] * i

    if(i == target):
      return factorials[i]

# recursion    
def recursion(number):
  if(number == 1):
    return 1;

  return number * recursion(number - 1)

def main():
  n = int(input())

  if (n == 0 or n == 1):
    print(1)

    return;

  print(dp(n))
  # print(recursion(n))

main()

