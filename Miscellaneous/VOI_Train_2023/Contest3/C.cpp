#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 7;
#define ll long long 
int n, k;
int cnt[N];

inline int digit_sum(int x) {
    int ans = 0;
    while (x > 0) {
        ans = ans + x % 10;
        x /= 10;
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

    cin >> n >> k;
    memset(cnt, 0, sizeof cnt);
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        cnt[a]++;
    }

    for (int i = 1000000; i >= 0; i--) {
        if (cnt[i] >= k) {
            cout << digit_sum(i);
            return 0;
        }
        else {
            k -= cnt[i];
            cnt[i - digit_sum(i)] += cnt[i];
        }
    }

    cout << 0;

    return 0;
}
