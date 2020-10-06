#include <string>
#include <iostream>
#include <vector>

using namespace std;

char vowel[5] = { 'a','e','i','o','u' };

int main() {
	string input, answer;
	getline(cin, input);
	int cur = 0;
	while (cur < input.size()) {
		answer += input[cur];
		for (int i = 0; i < 5; i++) {
			if (vowel[i] == input[cur]) {
				cur += 2;
				break;
			}
		}
		cur++;
	}
	cout << answer << endl;
	return 0;
}