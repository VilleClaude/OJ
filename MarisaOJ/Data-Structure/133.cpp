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
int p[N];
int Find(int u) {
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

    For (i, 1, n) {
        p[i] = i;
        vis[i] = 0;
    }

    For (i, 1, n) {
        int a;
        cin >> a;
        if (vis[a] == 0) {
            vis[a] = 1;
            if (a + 1 <= n) {
                if (vis[a + 1] == 1) {
                    int v = Find(a + 1);
                    p[a] = v;
                }
            }
            if (a - 1 >= 1) {
                if (vis[a - 1] == 1) {
                    int v = Find(a);
                    p[a - 1] = v;
                }
            }
            cout << a << " ";
        }
        else {
            int u;
            u = a;
            bool ok = 0;
            while (u <= n) {
                u = Find(u);
                if (u + 1 <= n) {
                    ok = 1;
                    cout << u + 1 << " ";
                    p[u] = u + 1;
                    vis[u + 1] = 1;
                    if (u + 2 <= n) {
                        if (vis[u + 2] == 1) {
                            int v = Find(u + 2);
                            p[u + 1] = v;
                        }
                    }
                }
                if (ok) break;
                if (u == n) break;
            }
            if (!ok) {
                u = 1;
                while (ok == 0) {
                    if (vis[u] == 0) {
                        vis[u] = 1;
                        cout << u << " ";
                        if (vis[u + 1] == 1) p[u] = Find(u + 1);
                        ok = 1;
                    }
                   else { u = Find(u);
                    ok = 1;
                    cout << u + 1 << " ";
                    p[u] = u + 1;
                    vis[u + 1] = 1;
                    if (vis[u + 2] == 1) {
                        int v = Find(u + 2);
                        p[u + 1] = v;
                    }
                   }
                }
            }
        }
    }

    return 0;
}


