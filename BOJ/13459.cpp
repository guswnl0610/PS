#include <stdio.h>
#define INIT 97659765

struct marble {
	int i;
	int j;
};

int n, m, result = INIT;
int map[15][15];
int di[4] = { -1,1,0,0 };
int dj[4] = { 0,0,-1,1 };
int cdi[4] = { 1,-1,0,0 };
int cdj[4] = { 0,0,1,-1 };

marble move(marble prev, int dir) {
	int ci = prev.i;
	int cj = prev.j;
	while (1) {
		int ni = ci + di[dir];
		int nj = cj + dj[dir];
		if (ni < 0 || ni >= n || nj < 0 || nj >= m) break;
		else {
			if (map[ni][nj] == 1) break;
			else if (map[ni][nj] == 2) {
				ci = ni;
				cj = nj;
				break;
			}
			else {
				ci = ni;
				cj = nj;
			}
		}
	}
	prev.i = ci;
	prev.j = cj;
	return prev;
}

int getDistance(marble prev, marble next) {
	int difi = prev.i - next.i;
	int difj = prev.j - next.j;
	if (difi < 0) difi *= -1;
	if (difj < 0) difj *= -1;
	return difi + difj;
}

void dfs(int depth, marble red, marble blue) {
	if (result != INIT) return;
	if (depth >= 10) return;
	for (int dir = 0; dir < 4; dir++) {
		bool rhole = false, bhole = false;
		marble nred = move(red, dir);
		marble nblue = move(blue, dir);
		if (map[nred.i][nred.j] == 2) rhole = true;
		if (map[nblue.i][nblue.j] == 2) bhole = true;
		if (bhole) continue;
		else if (rhole && !bhole) {
			result = depth + 1;
			return;
		}
		if (nred.i == nblue.i && nred.j == nblue.j) {
			int reddif = getDistance(red, nred);
			int bluedif = getDistance(blue, nblue);
			if (reddif < bluedif) {
				nblue.i += cdi[dir];
				nblue.j += cdj[dir];
			}
			else {
				nred.i += cdi[dir];
				nred.j += cdj[dir];
			}
		}
		dfs(depth + 1, nred, nblue);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	marble red, blue;
	for (int i = 0; i < n; i++) {
		char tmp[20];
		scanf("%s", tmp);
		for (int j = 0; j < m; j++) {
			char tmpchar = tmp[j];
			if (tmpchar == '#') map[i][j] = 1;
			else if (tmpchar == 'O') map[i][j] = 2;
			else {
				map[i][j] = 0;
				if (tmpchar == 'B') {
					blue.i = i;
					blue.j = j;
				}
				else if (tmpchar == 'R') {
					red.i = i;
					red.j = j;
				}
			}
		}
	}
	dfs(0, red, blue);
	if (result == INIT) printf("0");
	else printf("1");
	return 0;
}