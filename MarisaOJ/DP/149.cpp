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
const int  N = 5e3+7;
const int M = 1e9+7;
const ll oo = 3e18;

int n, a[N], b[N];
ll dp[N][N];
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
    For (j, 1, n) cin >> b[j];

    For (i, 1, n) {
        For (j, 1, n) {
            dp[i][j] = max(1ll * a[i] * b[j], dp[i - 1][j - 1] + 1ll * a[i] * b[j]);
        }
    }

    ll ans = -oo;
    For (i, 1, n) {
        For (j, 1, n) ans = max(ans, dp[i][j]);
    }

    cout << ans << '\n';
    return 0;
}


