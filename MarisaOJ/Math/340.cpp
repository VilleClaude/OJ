#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 7;
int cnt[N];

vector<int> g[N];

void sieve() {
    for (int i = 2; i <= N - 7; i ++) {
        for (int j = i; j <= N - 7; j += i) g[j].push_back(i);
    }
}


int main() {
    int n, a;
    cin >> n;
    sieve();
    memset(cnt, 0, sizeof cnt);
    for (int i = 1; i <= n; i++) {
        cin >> a;
        if (a == 1) continue;
        for (int divisors: g[a]) {
            cnt[divisors]++;
        }
    }

    for (int i = N - 7; i >= 1; i--) {
        if (cnt[i] >= 2) {
            cout << i;
            return 0;
        }
    }

    cout << 1;

    return 0;
}
