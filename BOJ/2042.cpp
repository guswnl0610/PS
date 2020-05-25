#include <stdio.h>
#include <vector>

using namespace std;

int n, m, k;
long long int numbers[1000010], sums[1000010];
long long int changes[1000010];
int check[1000010];
vector <int> changelog;

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &numbers[i]);
		if (i == 0) sums[i] = numbers[i];
		else sums[i] = numbers[i] + sums[i - 1];
	}
	for (int i = 0; i < m + k; i++) {
		long long int a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		if (a == 1) {
			long long int tmp = c - numbers[b - 1];
			changes[b - 1] = tmp;
			changelog.push_back(b - 1);
		}
		else {
			long long int ans = sums[c - 1] - sums[b - 2];
			for (int j = 0; j < changelog.size(); j++) {
				int cidx = changelog[j];
				if (cidx >= b - 1 && cidx <= c - 1 && check[cidx] == 0) {
					check[cidx] = 1;
					ans += changes[cidx];
				}
			}
			for (int j = 0; j < changelog.size(); j++) check[changelog[j]] = 0;
			printf("%lld\n", ans);
		}
	}
	return 0;
}