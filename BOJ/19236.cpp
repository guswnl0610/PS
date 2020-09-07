#include <cstdio>

struct fish {
	int id;
	int i;
	int j;
	int dir;
};

struct shark {
	int i;
	int j;
	int dir;
};

int di[8] = { -1,-1,0,1,1,1,0,-1 };
int dj[8] = { 0,-1,-1,-1,0,1,1,1 };
int result = 0;

void getResult(shark jaws, fish fishes[], int map[][5], int cnt) {
	map[jaws.i][jaws.j] = -1;
	for (int i = 1; i <= 16; i++) {
		if (fishes[i].id > 0) {
			fish f = fishes[i];
			int ni, nj, didx = f.dir, dcnt = 0;
			for (int j = 0; j < 8; j++) {
				ni = f.i + di[didx];
				nj = f.j + dj[didx];
				if (ni >= 0 && ni < 4 && nj >= 0 && nj < 4 && map[ni][nj] >= 0) {
					break;
				}
				didx++;
				if (didx >= 8)didx -= 8;
				dcnt++;
			}
			if (dcnt != 8) {
				int nextid = map[ni][nj];
				if (nextid == 0) {
					map[f.i][f.j] = 0;
					f.i = ni;
					f.j = nj;
					f.dir = didx;
					map[f.i][f.j] = f.id;
				}
				else {
					map[f.i][f.j] = nextid;
					fishes[nextid].i = f.i;
					fishes[nextid].j = f.j;
					f.i = ni;
					f.j = nj;
					f.dir = didx;
					map[f.i][f.j] = f.id;
				}
				fishes[f.id] = f;
			}
		}
	}//물고기 이동

	map[jaws.i][jaws.j] = 0;
	int curmap[4][4];
	fish curfishes[20];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			curmap[i][j] = map[i][j];
		}
	}
	for (int i = 1; i <= 16; i++) curfishes[i] = fishes[i];//현재값 저장

	bool isedible = false;
	int sni = jaws.i, snj = jaws.j;
	for (int i = 0; i < 4; i++) {
		sni += di[jaws.dir];
		snj += dj[jaws.dir];
		if (sni >= 0 && sni < 4 && snj >= 0 && snj < 4) {
			if (map[sni][snj] > 0) {
				isedible = true;
				int fid = map[sni][snj];
				fish nfish = fishes[fid];
				shark njaws;
				njaws.i = sni;
				njaws.j = snj;
				njaws.dir = nfish.dir;
				fishes[fid].id = -1;
				getResult(njaws, fishes, map, cnt + fid);
				for (int j = 0; j < 4; j++) {
					for (int k = 0; k < 4; k++) map[j][k] = curmap[j][k];
				}
				for (int j = 1; j <= 16; j++) fishes[j] = curfishes[j];
			}
		}
		else break;
	}//상어 이동
	if (!isedible) {
		if (result < cnt) result = cnt;
	}

}

int main() {
	fish fishes[20];
	int map[5][5] = {0,};
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int a, b;
			scanf("%d %d", &a, &b);
			map[i][j] = a;
			fish f;
			f.i = i;
			f.j = j;
			f.id = a;
			f.dir = b - 1;
			fishes[a] = f;
		}
	}
	int fid = map[0][0];
	fish f = fishes[fid];
	shark jaws;
	jaws.i = 0;
	jaws.j = 0;
	jaws.dir = f.dir;
	fishes[fid].id = -1;

	getResult(jaws, fishes, map, fid);
	printf("%d", result);
	return 0;
}