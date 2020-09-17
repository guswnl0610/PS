#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct dot {
	int i;
	int j;
	//int pipe;
};

int n, m;
int map[30][30], visited[30][30];
vector <string> strmap;
int di[4] = { -1,1,0,0 };
int dj[4] = { 0,0,-1,1 };
string pipes = "|-+1234";
int pipedirs[7][4] = { {1,1,0,0},{0,0,1,1},{1,1,1,1},
					   {0,1,0,1},{1,0,0,1},{1,0,1,0},{0,1,1,0} };
queue <dot> q;
dot blank;

int getPipeidx(int row, int col) {
	char tmp = strmap[row][col];
	for (int i = 0; i < 7; i++) {
		if (tmp == pipes[i]) return i;
	}
}

void getPosition() {
	while (!q.empty()) {
		dot front = q.front();
		q.pop();
		int fi = front.i;
		int fj = front.j;
		if (strmap[fi][fj] == 'M' || strmap[fi][fj] == 'Z' || strmap[fi][fj] == '.') {
			for (int i = 0; i < 4; i++) {
				int ni = fi + di[i];
				int nj = fj + dj[i];
				if (ni >= 0 && ni < n && nj >= 0 && nj < m && visited[ni][nj] == 0 && strmap[ni][nj] != '.') {
					visited[ni][nj] = 1;
					dot next;
					next.i = ni;
					next.j = nj;
					q.push(next);
				}
			}
		}
		else {
			int pidx = getPipeidx(fi, fj);
			for (int i = 0; i < 4; i++) {
				if (pipedirs[pidx][i] == 1) {
					int ni = fi + di[i];
					int nj = fj + dj[i];
					if (ni >= 0 && ni < n && nj >= 0 && nj < m && visited[ni][nj] == 0) {
						if (strmap[ni][nj] == '.') {
							map[fi][fj] = 1;
							blank.i = ni;
							blank.j = nj;
							dot next;
							next.i = ni;
							next.j = nj;
							q.push(next);
						}
						else {
							visited[ni][nj] = 1;
							dot next;
							next.i = ni;
							next.j = nj;
							q.push(next);
						}
					}
				}
			}
		}
	}
}

int main() {
	scanf("%d %d ", &n, &m);
	for (int i = 0; i < n; i++) {
		string tmp;
		getline(cin, tmp);
		strmap.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (strmap[i][j] == 'M' || strmap[i][j] == 'Z') {
				visited[i][j] = 1;
				dot d;
				d.i = i;
				d.j = j;
				q.push(d);
			}
		}
	}
	getPosition();
	int check[4] = {0,};
	for (int i = 0; i < 4; i++) {
		int ni = blank.i + di[i];
		int nj = blank.j + dj[i];
		if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
			if (map[ni][nj] == 1) check[i] = 1;
		}
	}
	int pidx;
	for (int i = 0; i < 7; i++) {
		bool flag = true;
		for (int j = 0; j < 4; j++) {
			if (check[j] != pipedirs[i][j]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			pidx = i;
			break;
		}
	}
	printf("%d %d %c", blank.i + 1, blank.j + 1, pipes[pidx]);
	return 0;
}
