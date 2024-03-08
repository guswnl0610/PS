import sys
import math

# sys.stdin = open('BOJ/4796/example.txt')
input = sys.stdin.readline
case = 1

# 캠핑장을 연속하는 P일 중, L일동안만 사용할 수 있다. 강산이는 이제 막 V일짜리 휴가를 시작했다. 
while(True):
  L, P, V = map(int, input().rstrip().split())

  if(L == 0 and P == 0 and V == 0):
    break

  result = math.floor(V / P) * L;
  mod = V % P;

  if(mod >= L):
    result = result + L
  else:
    result = result + mod

  print(f"Case {case}: {result}")

  case = case + 1

