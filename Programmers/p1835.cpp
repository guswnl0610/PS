#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

string friends = "ACFJMNRT";
int visited[10], line[10];
int answer = 0;
vector <string> compare;

bool isvalid() {
    string curstr;
    map <char, int> mp;
    for (int i = 0; i < 8; i++) {
        curstr += friends[line[i]];
        mp[curstr[i]] = i;
    }

    for (int i = 0; i < compare.size(); i++) {
        char a = compare[i][0];
        char b = compare[i][2];
        int distance = mp[a] - mp[b];
        distance = distance < 0 ? distance * -1 : distance;
        distance--;
        if (compare[i][3] == '=') {
            if (distance != compare[i][4] - '0') return false;
        }
        else if (compare[i][3] == '<') {
            if (distance >= compare[i][4] - '0') return false;
        }
        else if (compare[i][3] == '>') {
            if (distance <= compare[i][4] - '0') return false;
        }
    }
    return true;
}

void getResult(int index) {
    if (index >= 8) {
        if (isvalid()) answer++;
        return;
    }
    for (int i = 0; i < 8; i++) {
        if (visited[i] == 0) {
            visited[i] = 1;
            line[index] = i;
            getResult(index + 1);
            visited[i] = 0;
        }
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    answer = 0;
    memset(visited, 0, sizeof(visited));
    compare.clear();
    for (int i = 0; i < data.size(); i++) compare.push_back(data[i]);
    getResult(0);
    return answer;
}