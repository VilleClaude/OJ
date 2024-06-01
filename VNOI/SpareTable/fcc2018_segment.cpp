#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 7;
#define fi first
#define se second

pair<int,int> a[N], b[N];
int n, q;

int nxt[22][N];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
    }

    sort (a + 1, a + n + 1, [](pair<int,int> c, pair<int,int> d) {
        if (c.fi == d.fi) return c.se < d.se;
        return c.fi < d.fi;
    });

    int ma = -1;
    int sz = 0;
    a[0].fi = -1;
    a[n + 1].fi = -1;
    for (int i = 1; i <= n; i++) {
        if (a[i].fi == a[i + 1].fi) continue;
        else {
            if (ma < a[i].se) {
                sz++;
                b[sz] = a[i];
                ma = a[i].se;
            }
        }
    }

    n = sz;
    for (int j = 0; j <= 20; j++) {
        for (int i = 0; i <= n; i++) nxt[j][i] = -1;
    }
    for (int i = 1; i <= n; i++) a[i] = b[i];
    for (int i = 1; i <= n; i++) {
        int lo = i + 1;
        int hi = n;
        //cout << i << " " << a[i].fi << " " << a[i].se << ' ';
        int res = -1;
        while (lo <= hi) {
            int mid = lo + hi >> 1;
            //cout << mid << " " << a[mid].fi << " " << a[i].se + 2 << '\n';
            if (a[mid].fi < (a[i].se + 2)) res = mid, lo = mid + 1;
            else hi = mid - 1;
        }
        nxt[0][i] = res;
    }

    for (int j = 1; j <= 20; j++) {
        for (int i = 1; i <= n; i++)  nxt[j][i] = nxt[j - 1][nxt[j - 1][i]]; 
    }
    cin >> q;

    while (q--) {
        int l, r; cin >> l >> r;
        int lo = 1;
        int hi = n;
        int res = -1;
        while (lo <= hi) {
            int mid = lo + hi >> 1;
            if (a[mid].fi <= l) {
                res = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }
        if (res == -1) {
            cout << -1 << '\n';continue;
        }
        if (a[res].se >= r) {
            cout << 1 << '\n';
            continue;
        }
        int ans = 1;
        for (int i = 20; i >= 0; i--) {
            int j = nxt[i][res];
            if (j <= 0) continue;
            if (a[j].se < r) res = j, ans += (1 << i);
        }
        bool ok = 0;
        for (int i = 0; i < 20; i++) {
            int j = nxt[i][res];
            if (a[j].se >= r) {
                cout << ans + (1 << i) << '\n';
                ok = 1;
                break;
            }
        }
        if (ok == 0) cout << -1 << '\n';
      //  break;
    }
    return 0;
}
