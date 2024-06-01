#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 7;
int c, n;
int a[N];
#define fi first
#define se second
int dp[N];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> c >> n;
    for (int i = 0; i < N - 3; i++) dp[i] = 1e9 + 7;
    for (int i = 1; i <= n; i++) {
        a[i] = 0;
        for (int j = c - 1; j >= 0; j--) {
            char b;
            cin >> b;
            if (b == 'G') a[i] += (1 << (j));
        }
    }

    queue<pair<int,int>> q;
    for (int i = 1; i <= n; i++) q.push({a[i], 0}), dp[a[i]] = 0;
    while (q.size()) {
        pair<int,int> k = q.front();
        q.pop();
        for (int i = 0; i < c; i++) {
            if (dp[k.fi ^ (1 << i)] > k.se + 1) {
                dp[k.fi ^ (1 << i)] = k.se + 1;
                q.push({k.fi ^ (1 << i), k.se + 1});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << c - dp[(((1ll << c) - 1) ^ a[i])] << '\n';
    }
    return 0;
}
