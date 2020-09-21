#include <cstdio>
#include <cstring>

int T, n, m;
char hyuks[25][25];

int main() {
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			char tmp[25];
			scanf("%s", tmp);
			for (int j = 0; j < m; j++) hyuks[i][j] = tmp[j];
		}

	}
	return 0;
}