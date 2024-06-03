#include <bits/stdc++.h>

using namespace std;
#define ll long long 
#define all(v) v.begin(), v.end()
int n, x;
int a[45];

ll s = 0, ans = 0;
vector<ll> trai, phai;

inline void cal(int l, int r) {
    if (l > r) {
        trai.push_back(s);
        return;
    }
    for (int i = 0; i < 2; i++) {
        s += a[l] * i;
        cal(l + 1, r);
        s -= a[l] * i;
    }
}

inline void solve (int l, int r) {
    if (l > r) {
        phai.push_back(x - s);
        return;
    }
    for (int i = 0; i < 2; i++) {
        s += a[l] * i;
        solve(l + 1, r);
        s -= a[l] * i;
    }
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
    cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int mid = (n + 1) / 2;
    cal(1, mid);
    s = 0;
    solve(mid + 1, n);
    sort (all(trai));
    sort (all(phai));
    phai.push_back(1e18);
    int l, r;
    l = r = 0;
    for (ll num: trai) {
        while (phai[r] <= num) r++;
        while (phai[l] < num) l++;
        ans += (r - l);
    }

    cout << ans << '\n';
    return 0;
}
