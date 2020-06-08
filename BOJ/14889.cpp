#include <stdio.h>
#include <vector>

using namespace std;

int n, map[25][25], result = 86796978, team[25];

int getScore(vector <int>& tt) {
	int score = 0;

	for (int i = 0; i < tt.size() - 1; i++) {
		for (int j = i + 1; j < tt.size(); j++) {
			int n1 = tt[i];
			int n2 = tt[j];
			score += map[n1][n2];
			score += map[n2][n1];
		}
	}
	return score;
}

void getResult(int index, int steam) {
	if (index >= n) {
		if (steam == n / 2) {
			vector <int> st, lt;
			for (int i = 0; i < n; i++) {
				if (team[i] == 0) st.push_back(i);
				else lt.push_back(i);
			}
			int dif = getScore(st) - getScore(lt);
			if (dif < 0) dif *= -1;
			if (dif < result) result = dif;
		}
		return;
	}
	for (int i = 0; i < 2; i++) {
		team[index] = i;
		if (i == 0) getResult(index + 1, steam + 1);
		else getResult(index + 1, steam);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	getResult(0, 0);
	printf("%d", result);
	return 0;
}