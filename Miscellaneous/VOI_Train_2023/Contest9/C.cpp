#include <bits/stdc++.h>
#define int long long 
using namespace std;
#define fi first
#define se second
#define ii pair<int,int>
#define N 10000

int n, w;
ii a[N];
int dp[N];

// dp[j] = max(dp[j - a[i].fi] + a[i].se)
// j > w -> dp[w] = dp[j] because total weight >= w

bool check(int x) {
    for (int i = 1; i <= 10000; i++) dp[i] = -1e9;
    dp[0] = 0; 
    for (int i = 1; i <= n; i++) {
        for (int j = w; j >= 0; j--) {
            int mx = min(j + a[i].fi, w);
            dp[mx] = max(dp[mx], dp[j] + a[i].se - x * a[i].fi);
        }
    }
    return dp[w] > 0;
}

int32_t main() {
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

    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
        a[i].se *= 1000;
    }

    int l = 1;
    int r = 10000000;

    int res = -1;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    cout << res << '\n';
    return 0;
}
