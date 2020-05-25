#include <stdio.h>
#define INITVAL 9876987

struct dot {
	int i;
	int j;
	int type;
};

int n, m, map[15][15], result = INITVAL;
int di[4] = { -1,1,0,0 };
int dj[4] = { 0,0,-1,1 };
int cdi[4] = { 1,-1,0,0 };
int cdj[4] = { 0,0,1,-1 };

dot move(dot d, int dir) {
	int r = d.i;
	int c = d.j;
	while (1) {
		int ni = r + di[dir];
		int nj = c + dj[dir];
		if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
			if (map[ni][nj] == 0) {
				r = ni;
				c = nj;
			}
			else if (map[ni][nj] == -1) {
				r = ni;
				c = nj;
				break;
			}
			else break;
		}
		else break;
	}
	d.i = r;
	d.j = c;
	return d;
}

int getDistance(dot prev, dot next) {
	int disti = next.i - prev.i;
	int distj = next.j - prev.j;
	if (disti < 0) disti *= -1;
	if (distj < 0) distj *= -1;
	return disti + distj;
}

void dfs(int depth, dot r, dot b) {
	if (depth >= 10) return;
	if (depth >= result) return;
	for (int i = 0; i < 4; i++) {
		bool rhole = false, bhole = false;
		dot nred = move(r, i);
		dot nblue = move(b, i);
		if (map[nblue.i][nblue.j] == -1) bhole = true;
		else if (map[nred.i][nred.j] == -1) rhole = true;
		if (bhole) continue;
		else if (rhole && !bhole) {
			if (depth + 1 < result) result = depth + 1;
			continue;
		}
		if (nred.i == nblue.i && nred.j == nblue.j) {
			int rdist = getDistance(r, nred);
			int bdist = getDistance(b, nblue);
			if (bdist > rdist) {//blue가 더 멀음
				nblue.i += cdi[i];
				nblue.j += cdj[i];
			}
			else {//red가 더 멀음
				nred.i += cdi[i];
				nred.j += cdj[i];
			}
		}
		dfs(depth + 1, nred, nblue);
	}
}

int main() {
	dot r, b;
	r.type = 0;
	b.type = 1;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		char tmp[15];
		scanf("%s", tmp);
		for (int j = 0; j < m; j++) {
			if (tmp[j] == '.') map[i][j] = 0;
			else if (tmp[j] == '#') map[i][j] = 1;
			else if (tmp[j] == 'O') map[i][j] = -1;
			else if (tmp[j] == 'R') {
				r.i = i;
				r.j = j;
			}
			else if (tmp[j] == 'B') {
				b.i = i;
				b.j = j;
			}
		}
	}
	dfs(0, r, b);
	if (result == INITVAL) printf("-1");
	else printf("%d", result);
	return 0;
}