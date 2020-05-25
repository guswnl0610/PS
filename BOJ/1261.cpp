#include <stdio.h>
#include <queue>

using namespace std;

struct dot {
	int i;
	int j;
};

int n, m, map[110][110], d[110][110];
int di[4] = { -1,1,0,0 };
int dj[4] = { 0,0,-1,1 };
queue <dot> q;

void bfs(int r, int c) {
	dot start;
	start.i = r;
	start.j = c;
	q.push(start);
	while (!q.empty()) {
		dot f = q.front();
		q.pop();
		int fi = f.i;
		int fj = f.j;
		for (int i = 0; i < 4; i++) {
			int ni = fi + di[i];
			int nj = fj + dj[i];
			if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
				if (map[ni][nj] == 0 && d[fi][fj] < d[ni][nj]) {
					d[ni][nj] = d[fi][fj];
					dot next;
					next.i = ni;
					next.j = nj;
					q.push(next);
				}
				else if (map[ni][nj] == 1 && d[fi][fj] + 1 < d[ni][nj]) {
					d[ni][nj] = d[fi][fj] + 1;
					dot next;
					next.i = ni;
					next.j = nj;
					q.push(next);
				}
			}
		}
	}
}

int main() {
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
			d[i][j] = 987987;
		}
	}
	d[0][0] = 0;
	bfs(0, 0);
	printf("%d", d[n - 1][m - 1]);
	return 0;
}