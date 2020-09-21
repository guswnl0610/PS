#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cstdio>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    for (int i = 0; i < timetable.size(); i++) {
        string tt = timetable[i];
        string tmph, tmpm;
        tmph += tt[0];
        tmph += tt[1];
        tmpm += tt[3];
        tmpm += tt[4];
        int time = stoi(tmph) * 60 + stoi(tmpm);
        pq.push(time);
    }

    for (int i = 0; i < n - 1; i++) {
        int cur = 9 * 60 + i * t;
        int cnt = 0;
        while (!pq.empty() && cnt < m) {
            if (pq.top() <= cur) {
                cnt++;
                pq.pop();
            }
            else break;
        }
    }

    vector <int> waiting;
    int cur = 9 * 60 + t * (n - 1);
    while (!pq.empty() && waiting.size() <= m) {
        if (pq.top() <= cur) {
            waiting.push_back(pq.top());
            pq.pop();
        }
        else break;
    }
    int time;
    if (waiting.size() < m) time = cur;
    else time = waiting[m - 1] - 1;
    int hh = time / 60;
    int mm = time % 60;
    if (hh < 10) answer += "0";
    answer += to_string(hh) + ":";
    if (mm < 10) answer += "0";
    answer += to_string(mm);

    return answer;
}