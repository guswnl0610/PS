#include <cstdio>
#include <vector>

using namespace std;

vector <int> trees[15][15];
int n, m, years;
int map[15][15], A[15][15];
int di[8] = { -1,-1,-1,0,0,1,1,1 };
int dj[8] = { -1,0,1,-1,1,-1,0,1 };

void springAndSummer() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int treescnt = trees[i][j].size();
			for (int h = 0; h < treescnt; h++) {
				int age = trees[i][j][h];
				if (map[i][j] - age >= 0) {
					map[i][j] -= age;
					trees[i][j][h]++;
				}
				else {
					for (int l = treescnt - 1; l >= h; l--) {
						map[i][j] += trees[i][j][l] / 2;
						trees[i][j].pop_back();
					}
					break;
				}
			}
		}
	}
}

void autumn() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < trees[i][j].size(); k++) {
				if (trees[i][j][k] % 5 == 0) {
					for (int l = 0; l < 8; l++) {
						int ni = i + di[l];
						int nj = j + dj[l];
						if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
							trees[ni][nj].insert(trees[ni][nj].begin(), 1);
						}
					}
				}
			}
		}
	}
}

void winter() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] += A[i][j];
		}
	}
}

void getResult() {
	for (int i = 0; i < years; i++) {
		springAndSummer();
		autumn();
		winter();
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &years);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = 5;
			scanf("%d", &A[i][j]);
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		trees[x - 1][y - 1].push_back(z);
	}
	getResult();
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cnt += trees[i][j].size();
		}
	}
	printf("%d", cnt);
	return 0;
}