#include <stdio.h>
#define INITVAL 98778789

int n, m, h, map[35][35];
int result = INITVAL;

bool isValid() {
	for (int c = 0; c < m; c++) {
		int cur = c;
		for (int r = 0; r < n; r++) {
			if (map[r][cur] != 0) {
				if (cur < m - 1 && map[r][cur] == map[r][cur + 1]) cur++;
				else if (cur > 0 && map[r][cur] == map[r][cur - 1]) cur--;
			}
		}
		if (cur != c) return false;
	}
	return true;
}

bool isbuildable(int r, int c) {
	if (map[r][c] == 0 && map[r][c + 1] == 0) return true;
	else return false;
}

void getResult(int depth, int dest, int row, int col, int num) {
	if (result <= dest) return;
	if (depth >= dest) {
		if (isValid()) {
			if (result > dest) result = dest;
		}
		return;
	}
	for (int i = row; i < n; i++) {
		if (i > row) col = 0;
		for (int j = col; j < m - 1; j++) {
			if (isbuildable(i, j)) {
				map[i][j] = num;
				map[i][j + 1] = num;
				getResult(depth + 1, dest, i, j, num + 1);
				map[i][j] = 0;
				map[i][j + 1] = 0;
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &m, &h, &n);
	int cnt = 0;
	for (int i = 0; i < h; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		cnt++;
		map[a - 1][b - 1] = cnt;
		map[a - 1][b] = cnt;
	}
	if (isValid()) {
		printf("0");
		return 0;
	}
	for (int i = 1; i <= 3; i++) {
		getResult(0, i, 0, 0, cnt + 1);
	}
	if (result == INITVAL) printf("-1");
	else printf("%d", result);
	return 0;
}