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
int p[N];
int dp[103][1005];
void sieve() {
    p[0] = p[1] = 1;
    for (int i = 2; i * i <= N - 7; i++) {
        if (!p[i]) {
            for (int j = i * i; j <= N - 7; j += i) p[j] = 1;
        }
    }
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
    sieve();
    For (i, 0, k) dp[1][i] = 1;

    For (i, 2, n) {
        For (j, 0, k) {
            dp[i][j] = 0;
            For (h, 0, k) {
                if (!p[j + h]) dp[i][j] += dp[i - 1][h], dp[i][j] %= M;
            }
        }
    }

    int ans = 0;
    For (i, 0, k) {
        ans += dp[n][i];
        ans %= M;
    }

    cout << ans << '\n';

    return 0;
}


