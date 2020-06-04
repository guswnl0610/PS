#include <stdio.h>

int result, n;
int T[20], P[20];

void dfs(int date, int sum) {
	for (int i = date; i <= n; i++) {
		int ndate = i + T[i];
		if (ndate > n + 1) continue;
		dfs(ndate, sum + P[i]);
	}
	if (result < sum) result = sum;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &T[i], &P[i]);
	}
	dfs(1, 0);
	printf("%d", result);
	return 0;
}