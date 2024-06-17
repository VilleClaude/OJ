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

int length(int a) {
    int ans = 0;
    while (a > 0) ans++, a /= 10;
    return ans;
}

ll gop(ll a, ll b) {
    int len = length(b);
    for (int i = 1; i <= len; i++) a *= 10ll;
    a += b;
    return a;
}

int t;
void solve() {
    int n;
    ll l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    For (i, 0, n - 1) cin >> a[i];
    sort (all(a));

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int L = 0;
        int R = n - 1;
        int res = -1;
        while (L <= R) {
            int mid = L + R >> 1;
            if (gop(a[i], a[mid]) >= l) {
                res = mid;
                R = mid - 1;
            }
            else L = mid + 1;
        }

        int kq = -1;

        L = 0;
        R = n - 1;

        while (L <= R) {
            int mid = L + R >> 1;
            if (gop(a[i], a[mid]) <= r) {
                kq = mid;
                L = mid + 1;
            }
            else R = mid - 1;
        }

        if (res == -1 || kq == -1) continue;;
        if (res > kq) continue;
        ans += (kq - res + 1);
    }

    cout << ans << '\n';
}

int32_t main() {
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

    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}


