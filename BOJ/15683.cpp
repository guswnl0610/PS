#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

struct cctv {
	int i;
	int j;
	int t;
};

int n, m, map[10][10], cmap[10][10], result = 9877897;
int torotate[10];
vector <cctv> cctvs;

void north(int r, int c) {
	for (int i = r-1; i >= 0; i--) {
		if (map[i][c] != 6)cmap[i][c] = 1;
		else break;
	}
}

void south(int r, int c) {
	for (int i = r + 1; i < n; i++) {
		if (map[i][c] != 6)cmap[i][c] = 1;
		else break;
	}
}

void west(int r, int c) {
	for (int i = c-1; i >= 0; i--) {
		if (map[r][i] != 6) cmap[r][i] = 1;
		else break;
	}
}

void east(int r, int c) {
	for (int i = c + 1; i < m; i++) {
		if (map[r][i] != 6) cmap[r][i] = 1;
		else break;
	}
}

void rotateCCTV(int r, int c, int t, int rot) {
	if (t == 1) {
		if (rot == 0) {
			north(r, c);
		}
		else if (rot == 1) {
			east(r, c);
		}
		else if (rot == 2) {
			south(r, c);
		}
		else if (rot == 3) {
			west(r, c);
		}
	}
	else if (t == 2) {
		if (rot == 0) {
			north(r, c);
			south(r, c);
		}
		else {
			east(r, c);
			west(r, c);
		}
	}
	else if (t == 3) {
		if (rot == 0) {
			north(r, c);
			east(r, c);
		}
		else if (rot == 1) {
			east(r, c);
			south(r, c);
		}
		else if (rot == 2) {
			south(r, c);
			west(r, c);
		}
		else {
			west(r, c);
			north(r, c);
		}
	}
	else if (t == 4) {
		if (rot == 0) {
			north(r, c);
			east(r, c);
			south(r, c);
		}
		else if (rot == 1) {
			east(r, c);
			south(r, c);
			west(r, c);
		}
		else if (rot == 2) {
			south(r, c);
			west(r, c);
			north(r, c);
		}
		else {
			west(r, c);
			north(r, c);
			east(r, c);
		}
	}
	else {
		north(r, c);
		east(r, c);
		south(r, c);
		west(r, c);
	}
}

void getcmap() {
	for (int i = 0; i < cctvs.size(); i++) {
		cctv c = cctvs[i];
		rotateCCTV(c.i, c.j, c.t, torotate[i]);
	}
}

void getResult(int index) {
	if (index >= cctvs.size()) {
		memset(cmap, 0, sizeof(cmap));
		getcmap();
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 0 && cmap[i][j] == 0) cnt++;
			}
		}
		if (cnt < result) result = cnt;
		return;
	}
	int type = cctvs[index].t;
	if (type == 5) {
		torotate[index] = 0;
		getResult(index + 1);
	}
	else if (type == 2) {
		for (int i = 0; i < 2; i++) {
			torotate[index] = i;
			getResult(index + 1);
		}
	}
	else {
		for (int i = 0; i < 4; i++) {
			torotate[index] = i;
			getResult(index + 1);
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] >= 1 && map[i][j] <= 5) {
				cctv c;
				c.i = i;
				c.j = j;
				c.t = map[i][j];
				cctvs.push_back(c);
			}
		}
	}
	getResult(0);
	printf("%d", result);
	return 0;
}