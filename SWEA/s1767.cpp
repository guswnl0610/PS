#include <cstdio>
#include <vector>

using namespace std;

struct core {
	int i;
	int j;
};

vector <core> cores;
int maxcore, result, T, n;
int di[4] = { -1,1,0,0 };
int dj[4] = { 0,0,-1,1 };

bool isConnectable(core cc, int dir, int map[][15]) {
	int ni = cc.i + di[dir];
	int nj = cc.j + dj[dir];
	while (1) {
		if (ni < 0 || ni >= n || nj < 0 || nj >= n) break;
		if (map[ni][nj] != 0) return false;
		ni += di[dir];
		nj += dj[dir];
	}
	return true;
}

void getResult(int index, int ncore, int length, int map[][15]) {
	if (ncore + cores.size() - index < maxcore) return;
	if (index >= cores.size()) {
		if (ncore > maxcore) {
			maxcore = ncore;
			result = length;
		}
		else if (ncore == maxcore) {
			if (result > length) result = length;
		}
		return;
	}
	int curmap[15][15];//현재의 맵을 임시저장. 후에 재귀호출할때 초기화 용도
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) curmap[i][j] = map[i][j];
	}
	core cc = cores[index];
	if (cc.i == 0 || cc.i == n - 1 || cc.j == 0 || cc.j == n - 1){ //이미연결된경우
		getResult(index + 1, ncore+1, length, map);
	}
	else {
		bool isable = false;
		for (int dir = 0; dir < 4; dir++) {
			if (isConnectable(cc, dir, map)) {
				isable = true;
				int cnt = 0;
				int ni = cc.i + di[dir], nj = cc.j + dj[dir];
				for (int i = 0; i < n; i++) {
					if (ni >= 0 && ni < n && nj >= 0 && nj < n && map[ni][nj] == 0) {
						cnt++;
						map[ni][nj] = 2;
					}
					else break;
					ni += di[dir];
					nj += dj[dir];
				}
				getResult(index + 1, ncore + 1, length + cnt, map);

				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) map[i][j] = curmap[i][j];
				}

			}
		}
		if (!isable) getResult(index + 1, ncore, length, map);
		getResult(index + 1, ncore, length, map);
	}
}

int main() {
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d", &n);
		int map[15][15] = { 0, };
		cores.clear();
		maxcore = 0;
		result = 99876876;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &map[i][j]);
				if (map[i][j] == 1) {
					core cc;
					cc.i = i;
					cc.j = j;
					cores.push_back(cc);
				}
			}
		}
		getResult(0, 0, 0, map);
		printf("#%d %d\n", t, result);
	}
	return 0;
}