#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct balloon {
    int num;
    int index;
};

vector <balloon> balloons;

bool bcomp(balloon a, balloon b) {
    if (a.num < b.num) return true;
    else return false;
}

int solution(vector<int> a) {
    if (a.size() <= 2) return a.size();
    int answer = 0;
    
    for (int i = 0; i < a.size(); i++) {
        balloon bb;
        bb.num = a[i];
        bb.index = i;
        balloons.push_back(bb);
    }
    sort(balloons.begin(), balloons.end(), bcomp);

    int sidx, eidx;
    if (balloons[0].index < balloons[1].index) {
        sidx = balloons[0].index;
        eidx = balloons[1].index;
    }
    else {
        sidx = balloons[1].index;
        eidx = balloons[0].index;
    }

    for (int i = 2; i < a.size(); i++) {
        int cidx = balloons[i].index;
        if (sidx < cidx && cidx < eidx) continue;
        answer++;
        if (cidx < sidx) sidx = cidx;
        if (cidx > eidx) eidx = cidx;
    }
    return answer + 2;
}