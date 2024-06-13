#include <bits/stdc++.h>

#define For(i,a,b) for(int i = a; i <= b; i++)
#define Ford(i,a,b) for(int i = a; i >= b; i--)
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define all(v) v.begin(),v.end()
#define RRH(v) v.resize(unique(all(v)) - v.begin())

using namespace std;
const int  N = 1e6+7;
const int M = 1e9+7;
const ll oo = 3e18;

int n, k;
int a[N];

ll dp[1005][1005];
ll sum[N];
ll po(ll a, ll b) {
    if (b == 0) return 1;
    ll t = po(a, b / 2);
    t = t * t % M;
    if (b & 1) return t * a % M;
    return t;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

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

    For (i, 1, n) {
        cin >> a[i];
    }

    memset(dp, 0, sizeof dp);

    memset(sum, 0, sizeof sum);
    sum[0] = 1;

    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = 1ll * sum[j - 1] * a[i];
            dp[i][j] %= M;
        }

        for (int j = 1; j <= k; j++) {
            sum[j] += dp[i][j];
            sum[j] %= M;
        }
    }

    cout << sum[k] << '\n';

    return 0;
}


