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

int n, m;
int p[N];
int Find(int u) {
    if (u == p[u]) return u;
    p[u] = Find(p[u]);
    return p[u];
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

    cin >> n >> m;
    For (i, 1, n) p[i] = i;

    while (m--) {
        int t, u, v; cin >> t >> u >> v;
        if (t == 1) {
            u = Find(u);
            v = Find(v);
            if (u > v) swap(u, v);
            p[v] = u;
        }
        else {
            u = Find(u);
            v = Find(v);
            if (u == v) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}


