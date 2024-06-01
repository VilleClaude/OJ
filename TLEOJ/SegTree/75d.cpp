#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 7;
#define ll long long 
#define all(v) v.begin(), v.end()
int n, q, s, a[N];
int p[N];

void sieve() {
    for (int i = 1; i <= N - 7; i++) p[i] = i;
    for (int i = 2; i * i <= N - 7; i++) {
        if (p[i] == i) {
            for (int j = i * i; j <= N - 7; j += i) {
                if (p[j] == j) p[j] = i;
            }
        }
    }
}

vector<int> st[N];

void build (int id, int l, int r) {
    if (l == r) {
        while (p[a[l]] != 1) {
            st[id].push_back(p[a[l]]);
            a[l] /= p[a[l]];
        }
        return;
    }
    int mid = l + r >> 1;
    build (id * 2, l, mid);
    build (id * 2 + 1, mid + 1, r);
    st[id].resize(st[id * 2].size() + st[id * 2 + 1].size());
    merge(all(st[id * 2]), all(st[id * 2 + 1]), st[id].begin());
}

ll get(int id, int l, int r, int u, int v, int x, int y) {
    if (l > v || r < u) return 0;
    if (u <= l && r <= v) {
        return upper_bound(all(st[id]), y) - lower_bound(all(st[id]), x);
    }
    int mid = l + r >> 1;
    return get(id * 2, l, mid, u, v, x, y) + get(id * 2 + 1, mid + 1, r, u, v, x, y);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q >> s;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sieve();
    build (1, 1, n);
    ll ans = 0;
    while (q--) {
        ll x, y, z, t;
        cin >> x >> y >> z >> t;
        ll L, R, u, v;
        L = 1 + min((x + ans * s) % n, (y + ans * s) % n);
        R = 1 + max((x + ans * s) % n, (y + ans * s) % n);
        u = 1 + min((z + ans * s) % 1000000, (t + ans * s) % 1000000);
        v = 1 + max((z + ans * s) % 1000000, (t + ans * s) % 1000000);
        ans = get(1, 1, n, L, R, u, v);
        cout << ans << '\n';
    }
    return 0;
}
