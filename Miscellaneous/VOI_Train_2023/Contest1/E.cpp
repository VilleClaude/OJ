#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 7;
#define fi first
#define se second
#define ii pair<int,int> 
int n, m;
pair<int,int> a[N];
vector<int> que[N];

struct seg {
    int bit[N];
    seg() {
        memset(bit, 0, sizeof bit);
    }
    void up(int x, int val) {
        for (; x < N - 3; x += x& - x) bit[x] += val;
    }
    int get (int x) {
        int ans = 0;
        for (; x; x -= x& - x) ans += bit[x];
            return ans;
    }
} T;

vector<ii> b[N];

int res[N * 5];
vector<int> id_que[N];

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

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
        T.up(a[i].se, 1);
        b[a[i].fi].push_back({a[i].se, 1});
    }

    int id = 2;

    for (int i = 1; i <= m; i++) {
        int siz;
        cin >> siz;
        que[i].resize(siz);
        for (int j = 0; j < siz; j++) {
            cin >> que[i][j];
        }
        sort (que[i].begin(), que[i].end());
        if (1 <= que[i][0] - 1) {
            b[1].push_back({que[i][0] - 1, id});
            id_que[i].push_back(id);
            id++;
        }
        for (int j = 0; j < siz - 1; j++) {
            if (que[i][j] + 1 <= que[i][j + 1] - 1) {
                b[que[i][j] + 1].push_back({que[i][j + 1] - 1, id});
                id_que[i].push_back(id);
                id++;
            }
        }
        if (que[i][siz -1] + 1 <= 1000000) b[que[i][siz - 1] + 1].push_back({1000000, id}), id++, id_que[i].push_back(id - 1);
    }

    for (int i = 1; i <= 1000000; i++) {
        sort (b[i].begin(), b[i].end(), [](ii a, ii b) {
            return a.se > b.se;
        });
        for (auto x: b[i]) {
            if (x.se == 1) {
                T.up(x.fi, -1);
            }
            else {
                res[x.se] = T.get(x.fi);
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        int ans = n;
        for (int x: id_que[i]) ans -= res[x];
        cout << ans << '\n';
    }

    return 0;
}
