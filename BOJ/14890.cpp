#include <stdio.h>

int n, l, result;
int map[210][110];

bool checkLower(int r, int c, int cur, int next) {
	if (c + l > n) return false;
	for (int k = c + 1; k < c + l; k++) {
		if (map[r][k] != next) return false;
	}
	return true;
}

void getResult() {
	for (int r = 0; r < 2 * n; r++) {
		int cur = map[r][0];
		int cnt = 1, c = 1;
		bool isable = true;
		while (c < n) {
			int next = map[r][c];
			int dif = next - cur;
			if (dif < 0) dif *= -1;
			if (dif > 1) {
				isable = false;
				break;
			}
			if (cur < next) {
				if (cnt >= l) {
					cnt = 1;
					cur = next;
				}
				else {
					isable = false;
					break;
				}
			}
			else if (cur > next) {
				if (checkLower(r, c, cur, next)) {
					cur = next;
					cnt = 0;
					c += l;
					continue;
				}
				else {
					isable = false;
					break;
				}
			}
			else cnt++;
			c++;
		}
		if (isable) {
			result++;
		}
	}
}

int main() {
	scanf("%d %d", &n, &l);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = n; i < 2 * n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = map[j][i - n];
		}
	}
	getResult();
	printf("%d", result);
	return 0;
}