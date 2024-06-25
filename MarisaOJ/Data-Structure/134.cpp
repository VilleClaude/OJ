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

struct edge {
    int u, v, w;
} e[N];
int p[N];
ll ans = 0;

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

    For (i, 1, m) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }

    For (i, 1, n) p[i] = i;

    sort (e + 1, e + m + 1, [](edge a, edge b) {
        return a.w < b.w;
    });

    For (i, 1, m) {
        int u = e[i].u;
        int v = e[i].v;
        u = Find(u);
        v = Find(v);
        if (u == v) continue;
        ans += e[i].w;
        if (u > v) swap(u,v);
        p[v] = u;
    }

    cout << ans << '\n';

    return 0;
}


