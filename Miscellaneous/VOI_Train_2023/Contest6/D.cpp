#include <bits/stdc++.h>
#define int long long 
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

bool check(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

void solve() {
    int n;
    cin >> n;
    int f = n + 1;
    while(!check(f)) f++;
    int g = n;
    while (!check(g)) g--;
    int tu = g - 2;
    int mau = 2ll * g;
    tu *= f;
    tu += 2ll * (n - g + 1);
    mau *= f;
    int gc = __gcd(tu, mau);
    cout << tu / gc << "/" << mau / gc << '\n';
}

int32_t main() {
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

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}


