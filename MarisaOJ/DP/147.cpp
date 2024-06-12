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

ll dp[5005][5005];

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

    For (i, 1, n) {
        For (j, 0, k + 1) dp[i][j] = -oo;
    }

    For (j, 0, k + 1) dp[0][j] = 0;

    For (j, 0, k) {
        For (i, 1, n) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[i]);
            dp[i][j + 1] = max({dp[i - 1][j], dp[i - 1][j + 1], dp[i][j + 1]});
        }
    }


    ll ans = -oo;
    for (int i = 0; i <= k; i++) ans = max(ans, dp[n][i]);
        cout << ans << '\n';

    return 0;
}


