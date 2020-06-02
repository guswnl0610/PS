#include <stdio.h>

int n, m, result;
int map[510][510], visited[510][510];
int di[4] = { -1,1,0,0 };
int dj[4] = { 0,0,-1,1 };

void dfs1(int depth, int r, int c, int sum) {
	if (depth >= 3) {
		if (result < sum) result = sum;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int ni = r + di[i];
		int nj = c + dj[i];
		if (ni >= 0 && ni < n && nj >= 0 && nj < m && visited[ni][nj] == 0) {
			visited[ni][nj] = 1;
			dfs1(depth + 1, ni, nj, sum + map[ni][nj]);
			visited[ni][nj] = 0;
		}
	}
}

void dfs2(int depth, int r, int c, int sum) {
	if (depth >= 3) {
		if (result < sum) result = sum;
	}
	else if (depth == 1) {
		for (int i = 0; i < 4; i++) {
			int j = i + 1;
			if (j >= 4) j -= 4;
			int ni1 = r + di[i];
			int nj1 = c + dj[i];
			int ni2 = r + di[j];
			int nj2 = c + dj[j];
			if (ni1 >= 0 && ni1 < n && nj1 >= 0 && nj1 < m && visited[ni1][nj1] == 0) {
				if (ni2 >= 0 && ni2 < n && nj2 >= 0 && nj2 < m && visited[ni2][nj2] == 0) {
					visited[ni1][nj1] = 1;
					visited[ni2][nj2] = 1;
					dfs2(depth + 2, r, c, sum + map[ni1][nj1] + map[ni2][nj2]);
					visited[ni1][nj1] = 0;
					visited[ni2][nj2] = 0;
				}
			}
		}
	}
	else {
		for (int i = 0; i < 4; i++) {
			int ni = r + di[i];
			int nj = c + dj[i];
			if (ni >= 0 && ni < n && nj >= 0 && nj < m && visited[ni][nj] == 0) {
				visited[ni][nj] = 1;
				dfs2(depth + 1, ni, nj, sum + map[ni][nj]);
				visited[ni][nj] = 0;
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = 1;
			dfs1(0, i, j, map[i][j]);
			dfs2(0, i, j, map[i][j]);
			visited[i][j] = 0;
		}
	}
	printf("%d", result);
	return 0;
}