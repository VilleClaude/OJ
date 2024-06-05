#include <bits/stdc++.h>

using namespace std;

int t;
int n;
vector<int> g[1000000];
int dp[1000000];
void dfs(int u, int pre) {
    dp[u] = 1;
    int cnt = 0;
    for (int v: g[u]) {
        if (v == pre) continue;
        dfs(v, u);
        dp[u] = max(dp[v], dp[u]);
    }
    for (int v: g[u]) {
        if (v == pre) continue;
        if (dp[v] == dp[u]) cnt++;
    }
    dp[u] += (cnt > 1);
}

int main() {
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

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            g[i].clear();
        }
        for (int i = 1; i <= n; i++) dp[i] = 0;
        int root = -1;
        for (int i = 1; i <= n; i++) {
            int a;
            cin >> a;
            if (a != 0) g[i].push_back(a);
            if (a != 0) g[a].push_back(i);
            if (a == 0) root = i;
        }
        dfs(root, 0);
        cout << dp[root] << '\n';
    }
    return 0;
}
