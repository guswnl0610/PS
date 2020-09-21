#include <string>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

map <string, int> mp;
vector <string> candidates[10];
int maxsize = 0;
int check[10];

bool isCandidate(vector<vector<string>> relation) {
    mp.clear();
    for (int i = 0; i < relation.size(); i++) {
        string tmpkey = "";
        for (int j = 0; j < relation[i].size(); j++) {
            if (check[j] == 1) tmpkey += relation[i][j];
        }
        if (mp.count(tmpkey) != 0) return false;
        else mp[tmpkey] = 1;
    }
    return true;
}

bool validationCheck(int size) {
    for (int i = 1; i < size; i++) {
        for (int j = 0; j < candidates[i].size(); j++) {
            string candi = candidates[i][j];
            int cnt = 0;
            for (int k = 0; k < candi.size(); k++) {
                if (candi[k] == '1' && check[k] == 1) cnt++;
            }
            if (cnt == i) return false;
        }
    }
    return true;
}

void getResult(int index, int size , vector<vector<string>> relation){
    if (index >= maxsize) {
        int onecnt = 0;
        for (int i = 0; i < index; i++) {
            if (check[i] == 1) onecnt++;
        }
        if (onecnt == size) {
            if (size > 1) {
                if (!validationCheck(size)) return;
            }
            if (isCandidate(relation)) {
                string tmp = "";
                for (int i = 0; i < index; i++) {
                    tmp += check[i] + '0';
                }
                candidates[size].push_back(tmp);
            }
        }
        return;
    }
    for (int i = 0; i < 2; i++) {
        check[index] = i;
        getResult(index + 1, size, relation);
    }
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    maxsize = relation[0].size();
    for (int i = 1; i <= maxsize; i++) {
        getResult(0, i, relation);
    }
    for (int i = 1; i <= maxsize; i++) {
        answer += candidates[i].size();
    }
    return answer;
}