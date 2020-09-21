#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    for (int kidx = 0; kidx < queries.size(); kidx++) {
        string keyword = queries[kidx];
        bool isPre = true;
        if (keyword[0] == '?') isPre = false;
        string realkey = "";
        for (int i = 0; i < keyword.size(); i++) {
            if (keyword[i] != '?') realkey += keyword[i];
        }
        int cnt = 0;
        for (int widx = 0; widx < words.size(); widx++) {
            string lyrics = words[widx];
            if (lyrics.size() != keyword.size()) continue;
            if (realkey.size() == 0) {
                cnt++;
                continue;
            }
            bool isOK = true;
            if (isPre) {//앞에서부터 봄
                for (int i = 0; i < realkey.size(); i++) {
                    if (realkey[i] != lyrics[i]) {
                        isOK = false;
                        break;
                    }
                }
            }
            else {//뒤에서부터 봄
                for (int i = 0; i < realkey.size(); i++) {
                    if (realkey[realkey.size() - 1 - i] != lyrics[lyrics.size() - 1 - i]) {
                        isOK = false;
                        break;
                    }
                }
            }
            if (isOK) cnt++;
        }
        answer.push_back(cnt);
    }

    return answer;
}

