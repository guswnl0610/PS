#include <cstdio>

int n, m, bray[100010];

bool isPossible(int length) {
	int bcnt = 0, sum = 0;
	for (int i = 0; i < n; i++) {
		if (bray[i] > length) return false;
		sum += bray[i];
		if (sum > length) {
			bcnt++;
			sum = bray[i];
		}
		if (bcnt >= m) return false;
	}
	return true;
}

int main() {
	scanf("%d %d", &n, &m);
	long long int tmpsum = 0;
	long long int maxtape = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &bray[i]);
		tmpsum += bray[i];
		if (bray[i] > maxtape) maxtape = bray[i];
	}
	long long int s = maxtape, e = tmpsum, mid;
	while (s <= e) {
		mid = (s + e) / 2;
		if (isPossible(mid)) e = mid - 1;
		else s = mid + 1;
	}
	long long int smaller, bigger;
	if (s < e) {
		smaller = s;
		bigger = e;
	}
	else {
		smaller = e;
		bigger = s;
	}
	if (isPossible(smaller)) printf("%lld", smaller);
	else printf("%lld", bigger);
	return 0;
}