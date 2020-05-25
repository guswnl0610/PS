#include <stdio.h>

int n, map[25][25], result;

void move(int dir) {
	if (dir == 0) {
		for (int c = 0; c < n; c++) {
			bool flag = false;
			int toidx = 0;
			for (int r = 0; r < n; r++) {
				if (!flag && map[r][c] != 0) {
					int val = map[r][c];
					map[r][c] = 0;
					flag = true;
					map[toidx++][c] = val;
				}
				else if (flag && map[r][c] != 0) {
					int val = map[r][c];
					if (map[toidx - 1][c] == map[r][c]) {
						map[r][c] = 0;
						map[toidx - 1][c] *= 2;
						flag = false;
					}
					else {
						map[r][c] = 0;
						map[toidx++][c] = val;
					}
				}
			}
		}
	}
	else if (dir == 1) {
		for (int c = 0; c < n; c++) {
			bool flag = false;
			int toidx = n - 1;
			for (int r = n - 1; r >= 0; r--) {
				if (!flag && map[r][c] != 0) {
					int val = map[r][c];
					map[r][c] = 0;
					flag = true;
					map[toidx--][c] = val;
				}
				else if (flag && map[r][c] != 0) {
					int val = map[r][c];
					map[r][c] = 0;
					if (map[toidx + 1][c] == val) {
						map[toidx + 1][c] *= 2;
						flag = false;
					}
					else {
						map[toidx--][c] = val;
					}
				}
			}
		}
	}
	else if (dir == 2) {
		for (int r = 0; r < n; r++) {
			bool flag = false;
			int toidx = 0;
			for (int c = 0; c < n; c++) {
				if (!flag && map[r][c] != 0) {
					int val = map[r][c];
					map[r][c] = 0;
					map[r][toidx++] = val;
					flag = true;
				}
				else if (flag && map[r][c] != 0) {
					int val = map[r][c];
					map[r][c] = 0;
					if (map[r][toidx - 1] == val) {
						map[r][toidx - 1] *= 2;
						flag = false;
					}
					else {
						map[r][toidx++] = val;
					}
				}
			}
		}
	}
	else if (dir == 3) {
		for (int r = 0; r < n; r++) {
			bool flag = false;
			int toidx = n - 1;
			for (int c = n - 1; c >= 0; c--) {
				if (!flag && map[r][c] != 0) {
					int val = map[r][c];
					map[r][c] = 0;
					map[r][toidx--] = val;
					flag = true;
				}
				else if (flag && map[r][c] != 0) {
					int val = map[r][c];
					map[r][c] = 0;
					if (map[r][toidx + 1] == val) {
						map[r][toidx + 1] *= 2;
						flag = false;
					}
					else {
						map[r][toidx--] = val;
					}
				}
			}
		}
	}
}

void dfs(int depth) {
	if (depth >= 5) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] > result) result = map[i][j];
			}
		}
		return;
	}
	int tmpmap[25][25];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmpmap[i][j] = map[i][j];
		}
	}
	for (int dir = 0; dir < 4; dir++) {
		move(dir);
		dfs(depth + 1);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				map[i][j] = tmpmap[i][j];
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	dfs(0);
	printf("%d", result);
	return 0;
}