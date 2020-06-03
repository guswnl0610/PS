#include <stdio.h>

int n, b, c, map[1000010];
long long int result;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &map[i]);
	}
	scanf("%d %d", &b, &c);
	for (int i = 0; i < n; i++) {
		if (map[i] < b) result++;
		else {
			int dif = map[i] - b;
			if (dif % c == 0) result += (dif / c + 1);
			else result += (dif / c + 2);
		}
	}
	printf("%lld", result);
	return 0;
}