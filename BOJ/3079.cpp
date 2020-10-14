#include <cstdio>
#include <climits>

int n, m;
long long int arr[100010];

int main() {
	scanf("%d %d", &n, &m);
	long long int nmax = 0; //≥”...∂ßπÆ¿Ã¥Ÿ....
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if (nmax < arr[i]) nmax = arr[i];
	}

	long long int s = 0, mid;
	long long int e = m * nmax;
	long long int ans = e;
	while (s <= e) {
		mid = (s + e) / 2;
		long long int count = 0;
		for (int i = 0; i < n; i++) {
			count += mid / arr[i];
		}
		if (count >= m) {
			e = mid - 1;
			ans = ans < mid ? ans : mid;
		}
		else s = mid + 1;
	}

	printf("%lld", ans);
	
	return 0;
}