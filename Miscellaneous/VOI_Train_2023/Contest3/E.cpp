#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 1e6 + 7;
#define fi first
#define se second
#define ii pair<int,int>
int n;
int a[N];
long long m, ans = 0;
int cnt[N];
set<int> s;
ii b[N];

long long d[N];

int p[N], sz[N];

int Find(int u) {
    if (u == p[u]) return u;
    p[u] = Find(p[u]);
    return p[u];
}
bool vis[N];
void Join(int u, int v) {
    u = Find(u);
    v = Find(v);
    if (u == v) return;
    if (sz[u] < sz[v]) swap(u, v);
    cnt[sz[u]]--;
    sz[u] += sz[v];
    cnt[sz[u]]++;
    cnt[sz[v]]--;
    s.insert(sz[u]);
    p[v] = u;
    sz[v] = 0;
}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    #define TASK ""
    if (fopen (".inp", "r")) {
        freopen (".inp", "r", stdin);
        freopen (".out", "w", stdout);
    }
    if(fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }

    memset(cnt, 0, sizeof cnt);
    memset(d, 0, sizeof d);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = {a[i], i};
        p[i] = i;
        sz[i] = 1;
        vis[i] = 0;
    }
    cin >> m;
    sort (b + 1, b + n + 1);
    int last = 0;
    int j = 1;
    for (int i = 1; i <= n; i++) {
        while (b[j].fi < i && j <= n) {
            cnt[1]++;
            if (vis[b[j].se + 1] == 1) Join(b[j].se, b[j].se + 1);
            if (vis[b[j].se - 1] == 1) Join(b[j].se, b[j].se - 1);
            vis[b[j].se] = 1;
            j++;
        }
        vector<int> del;
        for (int x: s) {
            if (cnt[x] > 0) {
                d[x] += cnt[x] * (i - last);
            } 
            else del.push_back(x);
        }
        last = i;
        for (int x: del) {
            s.erase(x);
        }
    }

    for (int x: s) {
        if (cnt[x] > 0) {
            d[x] += cnt[x] * (n - last);
        }
    }

    for (int i = n; i >= 1; i--) {
        if (d[i] * i >= m) {
            ans = ans + (m / i) * (i - 1);
            if (m % i > 0) ans += ((m % i) - 1);
            break;
        }
        else {
            ans = ans + d[i] * (i - 1);
            m -= d[i] * i;
        }
    }
    cout << ans << '\n';

    return 0;
}
