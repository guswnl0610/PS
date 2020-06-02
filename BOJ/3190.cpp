#include <stdio.h>
#include <vector>

using namespace std;

struct dot {
	int i;
	int j;
};

vector <dot> snake;
int map[110][110], smap[110][110], check[100010];
int dir, time = 1 , n, k, l;
int di[4] = { 0,1,0,-1 };
int dj[4] = { 1,0,-1,0 };

void getResult() {
	while (1) {
		dot head = snake[0];
		int ni = head.i + di[dir];
		int nj = head.j + dj[dir];
		if (ni < 0 || ni >= n || nj < 0 || nj >= n) break;
		if (smap[ni][nj] == 1) break;

		if (map[ni][nj] == 1) {
			map[ni][nj] = 0;
		}
		else {
			dot tail = snake[snake.size() - 1];
			smap[tail.i][tail.j] = 0;
			snake.pop_back();
		}
		dot nhead;
		nhead.i = ni;
		nhead.j = nj;
		snake.insert(snake.begin(), nhead);
		smap[ni][nj] = 1;
		if (check[time] != 0) {
			int pdir = dir;
			dir += check[time];
			if (dir < 0) dir += 4;
			else if (dir >= 4) dir -= 4;
		}
		time++;
	}
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++) {
		int r, c;
		scanf("%d %d", &r, &c);
		map[r-1][c-1] = 1;
	}
	scanf("%d", &l);
	for (int i = 0; i < l; i++) {
		int t;
		char d;
		scanf("%d %c", &t, &d);
		if (d == 'L') check[t] = -1;
		else check[t] = 1;
	}
	smap[0][0] = 1;
	dot start;
	start.i = 0;
	start.j = 0;
	snake.push_back(start);
	getResult();
	printf("%d", time);
	return 0;
}