#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 7;

int bit[N], n, a[N], pos[N];

inline void up (int x, int val) {
    for (; x <= n; x += x& - x) bit[x] += val;
}

inline int get (int x) {
    int ans = 0;
    for (;x; x -= x& - x) ans += bit[x];
        return ans;
}

int f[N], g[N];

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

    memset(bit, 0, sizeof bit);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], pos[a[i]] = i;
    f[0] = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1];
        f[i] += (get(n) - get(pos[i]));
        up(pos[i], 1);
    }

    memset(bit, 0, sizeof bit);
    
    g[n + 1] = 0;

    for (int i = n; i >= 1; i--) {
        g[i] = g[i + 1];
        g[i] += get(pos[i] - 1);
        up(pos[i], 1);
    }

    long long ans = 0, temp, nt = 0;
    int res = 0;
    memset(bit, 0, sizeof bit);
    for (int i = 1; i <= n; i++) {
        nt += (get(n) - get(a[i]));
        up(a[i], 1);
    }

    f[0] = 1e6;
    g[n + 1] = 1e6;

    for (int i = 1; i <= n; i++) {
        temp = f[i - 1] + g[i + 1];
        temp = nt - temp;
        if (ans < temp) {
            ans = temp;
            res = i;
        }
    }

    cout << res << " " << ans << '\n';

    return 0;
}
