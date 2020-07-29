#include <cstdio>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

struct res {
	int num;
	string comms;
};

queue <res> q;
int T, B;
int visited[10010];

void getResult(int a) {
	res start;
	string tmp = "";
	start.num = a;
	start.comms = tmp;
	q.push(start);
	while (!q.empty())
	{
		res front = q.front();
		q.pop();
		if (front.num == B) {
			for (int i = 0; i < front.comms.size(); i++) {
				printf("%c", front.comms[i]);
			}
			printf("\n");
			return;
		}
		else {
			int cur = front.num;
			string curcomms = front.comms;
			int next = (cur * 2) % 10000;
			if (visited[next] == 0) {
				visited[next] = 1;
				res dres;
				dres.num = next;
				dres.comms = curcomms + 'D';
				q.push(dres);
			}
			next = cur - 1;
			if (next < 0) next = 9999;
			if (visited[next] == 0) {
				visited[next] = 1;
				res sres;
				sres.num = next;
				sres.comms = curcomms + 'S';
				q.push(sres);
			}
			next = (cur % 1000) * 10 + cur / 1000;
			if (visited[next] == 0) {
				visited[next] = 1;
				res lres;
				lres.num = next;
				lres.comms = curcomms + 'L';
				q.push(lres);
			}
			next = (cur % 10) * 1000 + cur / 10;
			if (visited[next] == 0) {
				visited[next] = 1;
				res rres;
				rres.num = next;
				rres.comms = curcomms + 'R';
				q.push(rres);
			}
		}
	}
}

int main() {
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		memset(visited, 0, sizeof(visited));
		int a;
		scanf("%d %d", &a, &B);
		visited[a] = 1;
		getResult(a);
		while (!q.empty()) q.pop();
	}
	return 0;
}
