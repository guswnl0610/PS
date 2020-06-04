#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

struct dot {
	int i;
	int j;
};

int n, m, result;
int map[10][10], visited[10][10];
int di[4] = { -1,1,0,0 };
int dj[4] = { 0,0,-1,1 };
vector <dot> viruses;
queue <dot> q;

void initQueue() {
	for (int i = 0; i < viruses.size(); i++) {
		dot v = viruses[i];
		visited[v.i][v.j] = 1;
		q.push(v);
	}
}

void spreadViruses() {
	while (!q.empty()) {
		dot f = q.front();
		q.pop();
		int fi = f.i;
		int fj = f.j;
		for (int i = 0; i < 4; i++) {
			int ni = fi + di[i];
			int nj = fj + dj[i];
			if (ni >= 0 && ni < n && nj >= 0 && nj < m && visited[ni][nj] == 0 && map[ni][nj] == 0) {
				visited[ni][nj] = 1;
				dot next;
				next.i = ni;
				next.j = nj;
				q.push(next);
			}
		}
	}
}

void getResult(int wallcnt, int row, int col) {
	if (wallcnt >= 3) {
		memset(visited, 0, sizeof(visited));
		initQueue();
		spreadViruses();
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 0 && visited[i][j] == 0) cnt++;
			}
		}
		if (cnt > result) result = cnt;
		return;
	}
	for (int i = row; i < n; i++) {
		if (i > row) col = 0;
		for (int j = col; j < m; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				getResult(wallcnt + 1, i, j);
				map[i][j] = 0;
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) {
				dot v;
				v.i = i;
				v.j = j;
				viruses.push_back(v);
			}
		}
	}
	getResult(0, 0, 0);
	printf("%d", result);
	return 0;
}