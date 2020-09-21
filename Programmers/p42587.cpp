#include <string>
#include <vector>
#include <queue>
#include <cstdio>

using namespace std;

queue <int> q;
priority_queue<int, vector<int>, less<int>> pq;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    for (int i = 0; i < priorities.size(); i++) {
        q.push(i);
        pq.push(priorities[i]);
    }
    while (1) {
        int front = q.front();
        q.pop();
        if (priorities[front] == pq.top()) {
            pq.pop();
            if (front == location) break;
            answer++;
        }
        else q.push(front);
    }
    printf("%d", answer);
    return answer;
}