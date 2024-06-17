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

int t;
int a[N];
void solve() {
    int n, p, q;
    cin >> n >> p >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1, greater<int>());
    ll ans = a[1] - a[n];
    vector<int> v;
    for (int i = 2; i < n; i++) v.push_back(abs(a[i]));
    sort(all(v), greater<int>());
    int sz = v.size();
    sz = min(p + q, sz) - 1;
    for (int i = 0; i <= sz; i++) ans += v[i];
    cout << ans << '\n';
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

    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}


