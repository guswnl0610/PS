#include <stdio.h>

int n, m, r, c, k;
int map[25][25];
int values[7], floor[7] = { 0,6,5,4,3,2,1 };
int dice[7] = {0,1,2,3,4,5,6};
int di[5] = { 0,0,0,-1,1 };
int dj[5] = { 0,1,-1,0,0 };

void roll(int dir) {
	int tmp = dice[1];
	if (dir == 1) {//east
		dice[1] = dice[3];
		dice[3] = dice[6];
		dice[6] = dice[4];
		dice[4] = tmp;
	}
	else if (dir == 2) {//west
		dice[1] = dice[4];
		dice[4] = dice[6];
		dice[6] = dice[3];
		dice[3] = tmp;
	}
	else if (dir == 3) {//north
		dice[1] = dice[2];
		dice[2] = dice[6];
		dice[6] = dice[5];
		dice[5] = tmp;
	}
	else if (dir == 4) {//south
		dice[1] = dice[5];
		dice[5] = dice[6];
		dice[6] = dice[2];
		dice[2] = tmp;
	}
}

void rollDice(int dir) {
	int ni = r + di[dir];
	int nj = c + dj[dir];
	if (ni < 0 || ni >= n || nj < 0 || nj >= m) return;
	roll(dir);
	int top = dice[1];
	int floorid = floor[top];
	if (map[ni][nj] == 0) 	map[ni][nj] = values[floorid];
	else {
		values[floorid] = map[ni][nj];
		map[ni][nj] = 0;
	}
	r = ni;
	c = nj;
	printf("%d\n", values[top]);
}

int main() {
	scanf("%d %d %d %d %d", &n, &m, &r, &c, &k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 0; i < k; i++) {
		int dir;
		scanf("%d", &dir);
		rollDice(dir);
	}
	return 0;
}