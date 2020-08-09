#include <string>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>

using namespace std;

int T;

vector <string> tokenizer(string data, char token) {
	vector <string> result;
	string tmp;
	stringstream ss(data);
	while (getline(ss, tmp, token)) {
		result.push_back(tmp);
	}
	return result;
}

int main() {
	scanf("%d ", &T);
	for (int t = 1; t <= T; t++) {
		string str;
		getline(cin, str);
		vector <string> input = tokenizer(str, ' ');
		vector <string> todelete;
		while (1) {
			getline(cin, str);
			vector <string> tmp = tokenizer(str, ' ');
			if (tmp[0] == "what") break;
			todelete.push_back(tmp[2]);
		}
		vector <string> result;
		for (int i = 0; i < input.size(); i++) {
			bool isokay = true;
			for (int j = 0; j < todelete.size(); j++) {
				if (input[i] == todelete[j]) {
					isokay = false;
					break;
				}
			}
			if (isokay) result.push_back(input[i]);
		}
		for (int i = 0; i < result.size(); i++) {
			for (int j = 0; j < result[i].size(); j++) {
				printf("%c", result[i][j]);
			}
			printf(" ");
		}
		printf("\n");
	}

	return 0;
}


