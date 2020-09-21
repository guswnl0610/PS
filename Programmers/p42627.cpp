#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdio>

using namespace std;

struct job {
    int st;
    int dt;
};

struct jcomp {
    bool operator()(job a, job b) {
        return a.dt > b.dt;
    }
};

priority_queue <job, vector<job>, jcomp> pq;

bool comp(vector <int>& v1, vector <int>& v2) {
    if (v1[0] < v2[0]) return true;
    else return false;
}

int solution(vector<vector<int>> jobs) {
    int answer = 0, idx = 0, time = 0;
    sort(jobs.begin(), jobs.end(), comp);
    while (idx < jobs.size() || !pq.empty()) {
        if (idx < jobs.size() && time >= jobs[idx][0]) {
            job j;
            j.st = jobs[idx][0];
            j.dt = jobs[idx][1];
            pq.push(j);
            idx++;
            continue;
        }
        if (!pq.empty()) {
            time += pq.top().dt;
            answer += time - pq.top().st;
            pq.pop();
        }
        else {
            time = jobs[idx][0];
        }
    }
    return answer / jobs.size();
}