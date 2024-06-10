#pragma GCC optimize("O3")
#pragma GCC optimize("O1")
#pragma GCC optimize("O1")
#pragma GCC target("avx2")
#pragma GCC optimize("unroll-loops")
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

char a[2004][2004];

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
const char dir[] = {'>', '<', 'v', '^'};
int dp[2004][2004];

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
    ii start_pos, end_pos;
    For (i, 1, n) {
        For (j, 1, m) {
            dp[i][j] = M;
            cin >> a[i][j];
            if (a[i][j] == 'o') {
                start_pos = {i, j};
            }
            if (a[i][j] == 'x') end_pos = {i, j};
        }
    }

    dp[start_pos.fi][start_pos.se] = 0;

    deque<ii> q;

    q.push_front(start_pos);

    while (q.size()) {
        ii k = q.front();
        q.pop_front();
        if (k == end_pos) continue;
        for (int i = 0; i <= 3; i++) {
            int x = dx[i] + k.fi;
            int y = dy[i] + k.se;
            if ((x < 0) || (y < 0) || (x > n) || (y > m)) continue;
            int weight = 1;
            if (a[k.fi][k.se] == 'o') weight = 0;
            else {
                char c = a[k.fi][k.se];
                if (c == dir[i]) weight = 0;
            }
            if (weight == 0) {
                if (dp[x][y] > dp[k.fi][k.se]) dp[x][y] = dp[k.fi][k.se], q.push_front({x, y});
            }
            else {
                if (dp[x][y] > dp[k.fi][k.se] + weight) {
                    dp[x][y] = dp[k.fi][k.se] + weight;
                    q.push_back({x, y});
                } 
            }
        }
    }

    cout << dp[end_pos.fi][end_pos.se] << '\n';

    return 0;
}


