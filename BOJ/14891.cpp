#include <stdio.h>
#include <string.h>

int gears[4][8], k;
int rot1[4] = { -1,1,-1,1 }, rot2[4] = { 1,-1,1,-1 };
int torotate[4];

void getTorotate(int idx) {
	torotate[idx] = 1;
	if (idx == 0) {
		if (gears[0][2] != gears[1][6] && torotate[1] == 0) getTorotate(1);
	}
	else if (idx == 3) {
		if (gears[3][6] != gears[2][2] && torotate[2] == 0) getTorotate(2);
	}
	else {
		if (gears[idx][2] != gears[idx + 1][6] && torotate[idx + 1] == 0) getTorotate(idx + 1);
		if (gears[idx][6] != gears[idx - 1][2] && torotate[idx - 1] == 0) getTorotate(idx - 1);
	}
}

void rotate(int idx, int dir) {
	if (dir == 1) {
		int tmp = gears[idx][7];
		for (int i = 7; i > 0 ; i--) {
			gears[idx][i] = gears[idx][i - 1];
		}
		gears[idx][0] = tmp;
	}
	else if(dir == -1){
		int tmp = gears[idx][0];
		for (int i = 0; i < 7; i++) {
			gears[idx][i] = gears[idx][i + 1];
		}
		gears[idx][7] = tmp;
	}
}

void rotateGear(int idx, int dir) {
	memset(torotate, 0, sizeof(torotate));
	getTorotate(idx);
	if (rot1[idx] == dir) {
		for (int i = 0; i < 4; i++) torotate[i] *= rot1[i];
	}
	else {
		for (int i = 0; i < 4; i++) torotate[i] *= rot2[i];
	}
	for (int i = 0; i < 4; i++) {
		rotate(i, torotate[i]);
	}
}

int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%1d", &gears[i][j]);
		}
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		rotateGear(a-1, b);
	}
	int ans = 0, val = 1;
	for (int i = 0; i < 4; i++) {
		if (gears[i][0] == 1) ans += val;
		val *= 2;
	}
	printf("%d", ans);
	return 0;
}