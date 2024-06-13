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
const int  N = 1e5+7;
const int M = 1e9+7;
const ll oo = 3e18;

int n, a[N], b[N];
ll dp[N][2][4];

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

    cin >> n;

    For (i, 1, n) cin >> a[i];
    For (i, 1, n) cin >> b[i];

    memset(dp, 0, sizeof dp);

    For (i, 1, n) {
        dp[i][0][1] = max(dp[i - 1][1][1], dp[i - 1][1][2]) + a[i];
        dp[i][0][2] = dp[i - 1][0][1] + a[i];
        dp[i][1][1] = max(dp[i - 1][0][1], dp[i - 1][0][2]) + b[i];
        dp[i][1][2] = dp[i - 1][1][1] + b[i];
    }

    cout << max({dp[n][0][1], dp[n][0][2], dp[n][1][1], dp[n][1][2]});


    return 0;
}


