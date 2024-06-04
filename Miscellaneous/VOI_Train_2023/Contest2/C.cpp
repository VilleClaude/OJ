#include <bits/stdc++.h>

using namespace std;

int q;
int p[1000008];

void sieve() {
    for (int i = 1; i <= 1000000; i++) {
        p[i] = i;
    }
    for (int j = 2; j * j <= 1000000; j++) {
        if (p[j] == j) {
            for (int i = j * j; i <= 1000000; i += j) {
                if (p[i] == i) p[i] = j;
            }
        }
    }
}

int cnt[1000009];

vector<int> prime_factor(int x) {
    vector<int> ans;
    int cur = p[x];
    while (cur != 1) {
        ans.push_back(cur);
        while (x % cur == 0) x /= cur;
        cur = p[x];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    #define TASK ""
    if (fopen (".inp", "r")) {
        freopen (".inp", "r", stdin);
        freopen (".out", "w", stdout);
    }
    if(fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }

    sieve();
    memset(cnt, 0, sizeof cnt);
    long long res = 0;
    cin >> q;
    while (q--) {
        int t, c;
        cin >> t >> c;
        vector<int> prime = prime_factor(c);
        int mx = prime.size();
        mx = (1 << mx);
        for (int mask = 0; mask < mx; mask++) {
            int k = 1;
            int d = 0;
            for (int i = 0; i < prime.size(); i++) {
                if (mask & (1 << i)) k *= prime[i], d++;
            }
            if (t == 1) {
                if (d & 1) {
                    res -= cnt[k];
                }
                else res += cnt[k];
                cnt[k]++;
            }
            else {
                cnt[k]--;
                if (d & 1) res += cnt[k];
                else res -= cnt[k];
            }
        }

        cout << res << '\n';
    }
    return 0;
}
