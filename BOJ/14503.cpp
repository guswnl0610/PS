#include <stdio.h>

struct robot {
	int i;
	int j;
	int d;
};

int n, m, result;
int map[60][60];
int di[4] = { -1,0,1,0 };
int dj[4] = { 0,1,0,-1 };
robot r;

void getResult() {
	while (1) {
		if (map[r.i][r.j] == 0) result++;
		map[r.i][r.j] = 2;
		int cnt = 0, nd = r.d;
		for (int i = 0; i < 4; i++) {
			nd--;
			if (nd < 0) nd += 4;
			int ni = r.i + di[nd];
			int nj = r.j + dj[nd];
			if (ni >= 0 && ni < n && nj >= 0 && nj < m && map[ni][nj] == 0) {
				r.i = ni;
				r.j = nj;
				r.d = nd;
				break;
			}
			else cnt++;
		}
		if (cnt == 4) {
			int cd = r.d + 2;
			if (cd >= 4) cd -= 4;
			int ni = r.i + di[cd];
			int nj = r.j + dj[cd];
			if (ni >= 0 && ni < n && nj >= 0 && nj < m && map[ni][nj] != 1) {
				r.i = ni;
				r.j = nj;
			}
			else return;
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	int ti, tj, td;
	scanf("%d %d %d", &ti, &tj, &td);
	r.i = ti;
	r.j = tj;
	r.d = td;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	getResult();
	printf("%d", result);
	return 0;
}