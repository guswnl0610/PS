#include <cstdio>
#include <vector>

using namespace std;

struct dot {
	int i;
	int j;
};

int di[4] = { 0,-1,0,1 };
int dj[4] = { 1,0,-1,0 };

int n, map[110][110];
vector <dot> curve;

void getNewGen() {
	int idx = curve.size() - 1;
	for (int i = idx; i > 0; i--) {
		int idif = curve[i - 1].i - curve[i].i;
		int jdif = curve[i - 1].j - curve[i].j;
		int nd;
		if (idif == di[0] && jdif == dj[0]) nd = 3;
		else if (idif == di[1] && jdif == dj[1]) nd = 0;
		else if (idif == di[2] && jdif == dj[2]) nd = 1;
		else if (idif == di[3] && jdif == dj[3]) nd = 2;
		dot newdot;
		newdot.i = curve[curve.size() - 1].i + di[nd];
		newdot.j = curve[curve.size() - 1].j + dj[nd];
		curve.push_back(newdot);
	}
}

void getCurve(int r, int c, int d, int g) {
	curve.clear();
	dot init, ndot;
	init.i = r;
	init.j = c;
	ndot.i = r + di[d];
	ndot.j = c + dj[d];
	curve.push_back(init);
	curve.push_back(ndot);
	for (int gen = 0; gen < g; gen++) {
		getNewGen();
	}
	for (int i = 0; i < curve.size(); i++) {
		dot dott = curve[i];
		map[dott.i][dott.j] = 1;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y, d, g;
		scanf("%d %d %d %d", &x, &y, &d, &g);
		getCurve(y, x, d, g);
	}
	int cnt = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j] == 1 && map[i + 1][j + 1] == 1) cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}