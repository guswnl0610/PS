#include <string>
#include <vector>

using namespace std;

int check[30];
int result[30], rr[30];
long long cnt = 0, fac;

void getResult(int index, int n, int k) {
    if (cnt >= k) return;
    if (index >= n) {
        cnt++;
        if (cnt == k) {
            for (int i = 0; i < n; i++) {
                rr[i] = result[i];
            }
        }
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (check[i] == 0) {
            check[i] = 1;
            result[index] = i;
            getResult(index + 1, n, k);
            check[i] = 0;
        }
    }
}

void getfacResult(int index, int n, int k) {
    if (cnt >= k) return;
    if (index >= n) {
        cnt++;
        if (cnt == k) {
            for (int i = 0; i < n; i++) {
                rr[i] = result[i];
            }
        }
        return;
    }
    for (int i = n; i >= 1; i--) {
        if (check[i] == 0) {
            check[i] = 1;
            result[index] = i;
            getfacResult(index + 1, n, k);
            check[i] = 0;
        }
    }
}

long long int factorial(int num) {
    if (num <= 1) return 1;
    return num * factorial(num - 1);
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    fac = factorial(n);
    if (k >= fac / 2) getfacResult(0, n, fac - k + 1);
    else getResult(0, n, k);
    for (int i = 0; i < n; i++) {
        answer.push_back(rr[i]);
    }
    return answer;
}