#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, int> strmap;
int n, m;
char pan[1010][1010];

bool isjb(int size) {
	strmap.clear();
	for (int col = 0; col < m; col++) {
		string tmp;
		for (int row = n - size; row < n; row++) {
			tmp += pan[row][col];
		}
		if (strmap.count(tmp) != 0) {
			return true;
		}
		else strmap[tmp] = 1;
	}
	return false;
}

int getResult() {
	int s = 0, e = n - 1, mid;
	while (s <= e) {
		mid = (s + e) / 2;
		if (isjb(mid)) {
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
	int bigger, smaller;
	if (e > s) {
		bigger = e;
		smaller = s;
	}
	else {
		bigger = s;
		smaller = e;
	}
	if (isjb(bigger)) return n - 1 - bigger;
	if (isjb(smaller)) return n - 1 - smaller;
	return n - 1;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		char tmp[1010];
		scanf("%s", tmp);
		for (int j = 0; j < m; j++) {
			pan[i][j] = tmp[j];
		}
	}
	printf("%d",getResult());

	return 0;
}