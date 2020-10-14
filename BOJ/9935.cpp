#include <string>
#include <iostream>
#include <stack>

using namespace std;

stack <char> st;
stack <char> tmp;

int main() {
	string inputstr, explodestr;
	getline(cin, inputstr);
	getline(cin, explodestr);
	for (int i = 0; i < inputstr.size(); i++) {
		st.push(inputstr[i]);
		if (st.top() == explodestr[explodestr.size() - 1] && st.size() >= explodestr.size()) {
			for (int j = explodestr.size() - 1; j >= 0; j--) {
				if (explodestr[j] == st.top()) {
					tmp.push(st.top());
					st.pop();
				}
				else break;
			}
			if (tmp.size() == explodestr.size()) {
				while (!tmp.empty()) tmp.pop();
			}
			else {
				while (!tmp.empty()) {
					st.push(tmp.top());
					tmp.pop();
				}
			}
		}
	}
	if (st.size() == 0) cout << "FRULA" << endl;
	else {
		string answer;
		while (!st.empty()) {
			answer.push_back(st.top());
			st.pop();
		}
		for (int i = answer.size() - 1; i >= 0; i--) {
			cout << answer[i];
		}
	}

	return 0;
}