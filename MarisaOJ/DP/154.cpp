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
const ll M = 123456789ll;
const ll oo = 3e18;

ll dp[N], su[N];
int n, a[N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    #define TASK ""
    if (fopen (".inp", "r")) {
        freopen (".inp", "r", stdin);
        freopen (".ans", "w", stdout);
    }
    if(fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".ans", "w", stdout);
    }
    memset(dp, 0, sizeof dp);

    cin >> n;
    For (i, 1, n) {
        cin >> a[i];
    }

    ll sum = 1;
    dp[a[1]] = 1;

    For (i, 2, n) {
        ll temp = 0;
        temp = (sum + 1ll);
        sum *= 2ll;
        sum++;
        sum %= M;
        sum -= dp[a[i]];
        sum %= M;
        sum += M;
        sum %= M;
        dp[a[i]] = temp;
    }

    cout << sum;
    


    return 0;
}
