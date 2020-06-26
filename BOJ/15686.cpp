#include <stdio.h>
#include <vector>

using namespace std;

struct dot {
	int i;
	int j;
};

vector <dot> chicks, houses;
int check[15], result = 9978798;
int n, m, map[55][55];

int getDistance() {
	int distance = 0;
	for (int i = 0; i < houses.size(); i++) {
		int tmp = 9778978;
		for (int j = 0; j < chicks.size(); j++) {
			if (check[j] == 1) {
				int di = houses[i].i - chicks[j].i;
				int dj = houses[i].j - chicks[j].j;
				if (di < 0) di *= -1;
				if (dj < 0) dj *= -1;
				if (di + dj < tmp) tmp = di + dj;
			}
		}
		distance += tmp;
	}
	return distance;
}

void getResult(int index) {
	if (index >= chicks.size()) {
		int cnt = 0;
		for (int i = 0; i < chicks.size(); i++) {
			if (check[i] == 1) cnt++;
		}
		if (cnt == m) {
			int distance = getDistance();
			if (distance < result) result = distance;
		}
		return;
	}
	for (int i = 0; i < 2; i++) {
		check[index] = i;
		getResult(index + 1);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) {
				dot d;
				d.i = i;
				d.j = j;
				houses.push_back(d);
			}
			else if (map[i][j] == 2) {
				dot d;
				d.i = i;
				d.j = j;
				chicks.push_back(d);
			}
		}
	}
	getResult(0);
	printf("%d", result);
	return 0;
}