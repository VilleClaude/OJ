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

int a, b;
int dp[506][505];

int cal(int a, int b) {
    if (a == b) return 0;
    if (dp[a][b] != 0) return dp[a][b];
    int ans = M;
    for (int i = 1; i <= b / 2; i++) {
        ans = min(ans, cal(a, i) + cal(a, b - i) + 1);
    }
    for (int i = 1; i <= a / 2; i++) {
        ans = min(ans, cal(i, b) + cal(a - i, b) + 1);
    }

    dp[a][b] = dp[b][a] = ans;
    return ans;
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

    cin >> a >> b;
    memset(dp, 0, sizeof dp);

    cout << cal(a, b);
    return 0;
}


