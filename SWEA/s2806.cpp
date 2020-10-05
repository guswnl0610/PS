#include <cstdio>

int T, n, check[15], result;
int map[15][15];

bool crossCheck(int row, int col) {
	int ni = row, nj = col;
	for (int i = 0; i < n; i++) {
		ni++;
		nj++;
		if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
			if (map[ni][nj] == 1) return false;
		}
		else break;
	}
	ni = row;
	nj = col;
	for (int i = 0; i < n; i++) {
		ni--;
		nj--;
		if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
			if (map[ni][nj] == 1) return false;
		}
		else break;
	}
	ni = row;
	nj = col;
	for (int i = 0; i < n; i++) {
		ni++;
		nj--;
		if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
			if (map[ni][nj] == 1) return false;
		}
		else break;
	}
	ni = row;
	nj = col;
	for (int i = 0; i < n; i++) {
		ni--;
		nj++;
		if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
			if (map[ni][nj] == 1) return false;
		}
		else break;
	}
	return true;
}

void getResult(int index) {
	if (index >= n) {
		result++;
	}
	for (int i = 0; i < n; i++) {
		if (check[i] == 0 && crossCheck(index, i)) {
			check[i] = 1;
			map[index][i] = 1;
			getResult(index + 1);
			map[index][i] = 0;
			check[i] = 0;
		}
	}
}

int main() {
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		result = 0;
		scanf("%d", &n);
		getResult(0);
		printf("#%d %d\n", t, result);
	}
	return 0;
}