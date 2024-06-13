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

int dp[N];
int n, k;

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
    dp[0] = 1;
    for (int i = 1; i <= k; i++) dp[i] = 0;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        for (int j = a; j <= k; j++) {
            dp[j] += dp[j - a];
            dp[j] %= M;
        }
    }

    cout << dp[k];
    return 0;
}


