import sys

# sys.stdin = open('BOJ/14889/example.txt')
sys.setrecursionlimit(10 ** 5)
input = sys.stdin.readline

N = int(input().rstrip())
S = [[0] * N for _ in range(N)]
scoreMap = {}
result = 99999999

def getScore(teamMembers):
  score = 0
  
  for idx, member1 in enumerate(teamMembers):
    for idx2, member2 in enumerate(teamMembers):
      if idx != idx2:
        score += S[member1][member2]

  return score

def getTeamCombination(team):
  if len(team) == N:
    if sum(team) == N / 2:
      global result

      team0 = [index for index, val in enumerate(team) if val == 0]
      team0.sort()
      team1 = [index for index, val in enumerate(team) if val == 1]
      team1.sort()

      team0Name = "".join(map(str, team0))
      team1Name = "".join(map(str, team1))

      # 이미 구한 적 있는 조합은 스킵
      if scoreMap.get(team0Name, False):
        return
      
      scoreMap[team0Name] = getScore(team0)
      scoreMap[team1Name] = getScore(team1)

      result = min(abs(scoreMap[team0Name] - scoreMap[team1Name]), result)

    return
  
  for i in range(2):
    getTeamCombination(team + [i])

for i in range(N):
  S[i] = list(map(int, input().rstrip().split()))

getTeamCombination([])
print(result)