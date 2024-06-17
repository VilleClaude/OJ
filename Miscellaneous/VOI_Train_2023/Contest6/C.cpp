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
vector<int> g[N];
ii a[N];
vector<ii> adj[N];
ll d[N];

void bfs (int s) {
    For (i, 1, n) d[i] = M;
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while (q.size()) {
        int k = q.front();
        q.pop();
        for (int v: g[k]) {
            if (d[k] + 1 <= a[s].se) {
                if (d[v] > d[k] + 1) {
                    d[v] = d[k] + 1;
                    q.push(v);
                }
            } 
        }
    }

    for (int i = 1; i <= n; i++) {
        if (i == s) continue;;
        if (d[i] == M) continue;;
        adj[s].push_back({i, a[s].fi});
    }
}

void dij() {
    For (i, 1, n) d[i] = oo;
    d[1] = 0;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> q;
    q.push({0, 1});
    while(q.size()) {
        ii k = q.top();
        q.pop();
        if (k.fi != d[k.se]) continue;
        for (auto v: adj[k.se]) {
            if (d[v.fi] > k.fi + v.se) {
                d[v.fi] = k.fi + v.se;
                q.push({d[v.fi], v.fi});
            }
        }
    }
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

    For (i, 1, n) {
        cin >> a[i].fi >> a[i].se;
    }

    For (i, 1, m) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    For (i, 1, n) bfs(i);

    dij();

    cout << d[n] << '\n';

    return 0;
}


