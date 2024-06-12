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

ll dp[N];
int n, s;

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
    memset(dp, 0, sizeof dp);
    dp[0] = 0;

    cin >> n >> s;

    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        for (int j = s; j >= a; j--) {
            dp[j] = max(dp[j - a] + b, dp[j]);
        }
    }

    cout << *max_element(dp + 1, dp + s + 1);

    return 0;
}


