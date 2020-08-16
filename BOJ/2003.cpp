#include <cstdio>

int map[10010];

int main() {
	int n, result = 0;
	long long int m;
	scanf("%d %lld", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &map[i]);
	}
	int s = 0, e = 0;
	long long int sum = map[0];
	while (e < n) {
		if (sum >= m) {
			if (sum == m) result++;
			sum -= map[s];
			s++;
		}
		else {
			e++;
			sum += map[e];
		}
	}
	printf("%d", result);
	return 0;
}