import sys

sys.stdin = open('BOJ/1212/example.txt', 'r');

input = sys.stdin.readline

number = input().rstrip()

# wow.. https://www.daleseo.com/python-int-bases/

print(format(int('0o' + number, 8), 'b'))