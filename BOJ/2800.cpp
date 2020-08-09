//#include <cstdio>
//#include <cstring>
//#include <string>
//#include <algorithm>
//#include <vector>
//#include <stack>
//
//using namespace std;
//
//stack <int> st;
//vector <string> deleted;
//int gidxs[15][2];
//int check[20];
//int glen;
//string input = "";
//
//bool strsort(string s1, string s2) {
//	return s1 < s2;
//}
//
//string deleteg() {
//	string newstr = "";
//	int topass[210] = { 0, };
//	for (int i = 0; i < glen; i++) {
//		if (check[i] == 1) {
//			int sidx = gidxs[i][0];
//			int lidx = gidxs[i][1];
//			topass[sidx] = 1;
//			topass[lidx] = 1;
//		}
//	}
//	for (int i = 0; i < input.size(); i++) {
//		if (topass[i] == 0) newstr += input[i];
//	}
//	return newstr;
//}
//
//void getNewStrings(int depth, int size) {
//	if (depth >= glen) {
//		int onecnt = 0;
//		for (int i = 0; i < depth; i++) {
//			if (check[i] == 1) onecnt++;
//		}
//		if (onecnt == size) {
//			string newstring = deleteg();
//			deleted.push_back(newstring);
//		}
//		return;
//	}
//	for (int i = 0; i < 2; i++) {
//		check[depth] = i;
//		getNewStrings(depth + 1, size);
//	}
//}
//
//int main() {
//	char tmp[210];
//	scanf("%s", tmp);
//	for (int i = 0; i < strlen(tmp); i++) {
//		input += tmp[i];
//	}
//	for (int i = 0; i < input.size(); i++) {
//		if (input[i] == '(') {
//			st.push(i);
//		}
//		else if (input[i] == ')') {
//			int sidx = st.top();
//			int lidx = i;
//			gidxs[glen][0] = sidx;
//			gidxs[glen][1] = lidx;
//			glen++;
//			st.pop();
//		}
//	}
//	for (int toDelSize = 1; toDelSize <= glen; toDelSize++) {
//		getNewStrings(0,toDelSize);
//	}
//	sort(deleted.begin(), deleted.end(), strsort);
//	for (int i = 0; i < deleted.size(); i++) {
//		if (i != 0 && deleted[i].compare(deleted[i - 1]) == 0) continue;
//		for (int j = 0; j < deleted[i].size(); j++) {
//			printf("%c", deleted[i][j]);
//		}
//		printf("\n");
//	}
//
//	return 0;
//}