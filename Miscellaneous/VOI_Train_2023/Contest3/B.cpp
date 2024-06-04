#include <bits/stdc++.h>

using namespace std;
#define ll long long 
const int M = 1e9 + 7;
ll dp[3001][3001], cnt[3004][3004];

int n;
ll a[4000], pre[4000];

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
    memset(dp, 0, sizeof dp);
    memset(cnt, 0, sizeof cnt);
    dp[0][0] = 1;
    cnt[0][0] = 1;
    cin >> n;
    pre[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i; j >= 1; j--) {
            dp[i][j] = cnt[pre[i] % j][j - 1];
            cnt[pre[i] % (j + 1)][j] += dp[i][j];
            cnt[pre[i] % (j + 1)][j] %= M;
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = ans + dp[n][i];
        ans %= M;
    }

    cout << ans << '\n';

    return 0;
}
