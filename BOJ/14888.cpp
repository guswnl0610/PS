#include <stdio.h>

int n, nums[15], ops[4];
long long int minval = 9879988797, maxval = -9879988797;

long long int getNewval(long long int prev,	long long int next, int op) {
	if (op == 0) return prev + next;
	else if (op == 1) return prev - next;
	else if (op == 2) return prev * next;
	else return prev / next;
}

void getResult(int index, long long int ans) {
	if (index >= n) {
		if (ans < minval) minval = ans;
		if (ans > maxval) maxval = ans;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (ops[i] > 0) {
			ops[i]--;
			getResult(index + 1, getNewval(ans, nums[index], i));
			ops[i]++;
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &nums[i]);
	}
	for (int i = 0; i < 4; i++) {
		scanf("%d", &ops[i]);
	}
	getResult(1, nums[0]);
	printf("%lld\n%lld", maxval, minval);
	return 0;
}