import sys

# sys.stdin = open('BOJ/25501/example.txt')
input = sys.stdin.readline

recursionCount = 0

def recursion(s, l, r):
    global recursionCount
    recursionCount = recursionCount + 1

    if l >= r: return 1
    elif s[l] != s[r]: return 0
    else: return recursion(s, l+1, r-1)

def isPalindrome(s):
    return recursion(s, 0, len(s)-1)

def main():
  global recursionCount
  n = int(input().rstrip())

  for _ in range(n):
    string = input().rstrip()

    recursionCount = 0

    print(isPalindrome(string), recursionCount)

main()