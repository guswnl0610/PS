#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, v;
int dvisited[1010], bvisited[1010];
vector <int> graph[1010];
queue <int> q;

void dfs(int cur) {
	dvisited[cur] = 1;
	printf("%d ", cur);
	for (int i = 0; i < graph[cur].size(); i++) {
		int next = graph[cur][i];
		if (dvisited[next] == 0) {
			dfs(next);
		}
	}
}

void bfs(int start) {
	q.push(start);
	bvisited[start] = 1;
	while (!q.empty()) {
		int f = q.front();
		q.pop();
		printf("%d ", f);
		for (int i = 0; i < graph[f].size(); i++) {
			int next = graph[f][i];
			if (bvisited[next] == 0) {
				bvisited[next] = 1;
				q.push(next);
			}
		}
	}
}


int main() {
	scanf("%d %d %d", &n, &m, &v);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (graph[i].size() > 1) {
			sort(graph[i].begin(), graph[i].end());
		}
	}
	dfs(v);
	printf("\n");
	bfs(v);


	return 0;
}