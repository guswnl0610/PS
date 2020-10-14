#include <string>
#include <vector>
#include <cstdio>

using namespace std;

bool isPossible(int niniz, int k, vector<int> &stones) {
    int counter = 0; // 못건너가는 돌
    for (int i = 0; i < k; i++) {
        if (stones[i] < niniz) counter++;
    }
    if (counter == k) return false;
    for (int i = k; i < stones.size(); i++) {
        if (stones[i - k] < niniz) counter--;
        if (stones[i] < niniz) counter++;
        if (counter >= k) return false;
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int maxval = 0;
    for (int i = 0; i < stones.size(); i++) {
        if (stones[i] > maxval) maxval = stones[i];
    }
    int s = 0, e = maxval, mid, answer = 0;
    while (s <= e) {
        mid = (s + e) / 2;
        if (isPossible(mid, k, stones)) {
            s = mid + 1;
            answer = mid > answer ? mid : answer;
        }
        else e = mid - 1;
    }
    return answer;
}