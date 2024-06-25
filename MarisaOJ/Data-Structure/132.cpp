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

int n;
ii a[N];

vector<int> g[N];
int p[N], sz[N];

int Find (int u) {
    if (u == p[u]) return u;
    p[u] = Find(p[u]);
    return p[u];
}

bool vis[N];

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

    For (i, 1, n) cin >> a[i].fi, a[i].se = i, p[i] = i, sz[i] = 1, vis[i] = 0;

    For (i, 1, n - 1) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    sort (a + 1, a + n + 1, [](ii a, ii b) {
        return a.fi < b.fi;
    });

    ll ans = 0;

    For (i, 1, n) {
        vis[a[i].se] = 1;

        ll sum = 0;

        for (int v: g[a[i].se]) {
            if (vis[v] == 1) {
                v = Find(v);
                int u = Find(a[i].se);
                if (u != v) {
                    ans = ans + 1ll * a[i].fi * sum * sz[v];
                    sum += sz[v];
                    if (sz[u] < sz[v]) swap(u, v);
                    sz[u] += sz[v];
                    p[v] = u;
                }
            }
        }

        ans = ans + 1ll * sum * a[i].fi;
    }

    For (i, 1, n) {
        p[i] = i;
        sz[i] = 1;
        vis[i] = 0;
    }

    sort (a + 1, a + n + 1, [](ii a, ii b) {
        return a.fi > b.fi;
    });

    For (i, 1, n) {
        vis[a[i].se] = 1;

        ll sum = 0;

        for (int v: g[a[i].se]) {
            if (vis[v] == 1) {
                v = Find(v);
                int u = Find(a[i].se);
                if (u != v) {
                    ans = ans - 1ll * a[i].fi * sum * sz[v];
                    sum += sz[v];
                    if (sz[u] < sz[v]) swap(u, v);
                    sz[u] += sz[v];
                    p[v] = u;
                }
            }
        }

        ans = ans - 1ll * sum * a[i].fi;
    }

    cout << ans << '\n';
    return 0;
}


