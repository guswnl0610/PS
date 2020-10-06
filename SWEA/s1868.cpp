#include <cstdio>
#include <cstring>

int T, n, answer;
int map[310][310], visited[310][310];
int di[8] = { -1,-1,-1,0,0,1,1,1 };
int dj[8] = { -1,0,1,-1,1,-1,0,1 };

void dfs(int row, int col) {
	visited[row][col] = 1;
	int trapcnt = 0;
	for (int i = 0; i < 8; i++) {
		int ni = row + di[i];
		int nj = col + dj[i];
		if (ni >= 0 && ni < n && nj >= 0 && nj < n && map[ni][nj] > 0) trapcnt++;
	}
	if (trapcnt == 0) {
		for (int i = 0; i < 8; i++) {
			int ni = row + di[i];
			int nj = col + dj[i];
			if (ni >= 0 && ni < n && nj >= 0 && nj < n && visited[ni][nj] == 0) {
				dfs(ni, nj);
			}
		}
	}
}


void getResult() {
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 || visited[i][j] == 1) continue;
			int trapcnt = 0;
			for (int k = 0; k < 8; k++) {
				int ni = i + di[k];
				int nj = j + dj[k];
				if (ni >= 0 && ni < n && nj >= 0 && nj < n && map[ni][nj] > 0) trapcnt++;
			}
			if (trapcnt == 0) {
				dfs(i, j);
				answer++;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0 && visited[i][j] == 0) {
				dfs(i, j);
				answer++;
			}
		}
	}
}

int main() {
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d", &n);
		answer = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				char tmp;
				scanf(" %c", &tmp);
				if (tmp == '*') map[i][j] = 1;
				else if (tmp == '.') map[i][j] = 0;
			}
		}
		getResult();

		printf("#%d %d\n", t, answer);
	}
	return 0;
}