#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 7;
#define ll long long 
#define fi first
#define se second
pair<int,ll> bit[N];
int n, k;
const ll oo = 1e18;

inline void up (int x, int val) {
    int vl = x - 1;
    vl *= val;
    for (; x <= N - 4; x += x& - x) bit[x].fi += val, bit[x].se += vl;
}

inline pair<int,ll> get(int x) {
    pair<int,ll> ans;
    for (;x; x -= x& - x) {
        ans.fi += bit[x].fi;
        ans.se += bit[x].se;
    }
    return ans;
}

int a[N];

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

    cin >> n >> k;

    int me = k;
    if (k % 2 == 0) me += 2;
    else me += 1;
    me /= 2;

    for (int i = 1; i <= n; i++) cin >> a[i];
    a[0] = -1;
    for (int i = 1; i < k; i++) {
        up(a[i] + 1, 1);
    }

    int ans_trc = N - 7;
    int med;
    ll ans = oo;

    pair<int,int> res_range;

    for (int i = k; i <= n; i++) {
        int ok = 0;
        if (a[i - k] != -1) {
            if (a[i - k] < ans_trc) ok += 1;
            else ok -= 1;
            up(a[i - k] + 1, -1);
        }
        if (a[i] > ans_trc) ok += 1;
        else ok -= 1;
        up(a[i] + 1, 1);
        if (ok == 0) {
            int l = 0;
            int r = N;
            int res;
            while (l <= r) {
                int mid = l + r >> 1;
                pair<int,ll> temp = get(mid + 1);
                if (temp.fi >= me) {
                    res = mid;
                    r = mid - 1;
                }
                else l = mid + 1;
            }
            ll temp = 0;
            pair<int,ll> s, ss;
            s = get(res);
            temp = temp + 1ll * s.fi * res - s.se;
            ss = get(1000001);
            ss.fi -= s.fi;
            ss.se -= s.se;
            temp = temp + ss.se - 1ll * ss.fi * res;
            if (temp < ans) {
                ans = temp;
                res_range = {i - k + 1, i};
                med = res;
            }
            ans_trc = res;
        }
        if (ok < 0) {
            int l = 0;
            int r = ans_trc;
            int res;
            while (l <= r) {
                int mid = l + r >> 1;
                pair<int,ll> temp = get(mid + 1);
                if (temp.fi >= me) {
                    res = mid;
                    r = mid - 1;
                }
                else l = mid + 1;
            }
            ll temp = 0;
            pair<int,ll> s, ss;
            s = get(res);
            temp = temp + 1ll * s.fi * res - s.se;
            ss = get(1000001);
            ss.fi -= s.fi;
            ss.se -= s.se;
            temp = temp + ss.se - 1ll * ss.fi * res;
            if (temp < ans) {
                ans = temp;
                res_range = {i - k + 1, i};
                med = res;
            }
            ans_trc = res;
        }
        if (ok > 0) {
            int l = ans_trc;
            int r = N - 7;
            int res;
            while (l <= r) {
                int mid = l + r >> 1;
                pair<int,ll> temp = get(mid + 1);
                if (temp.fi >= me) {
                    res = mid;
                    r = mid - 1;
                }
                else l = mid + 1;
            }
            ll temp = 0;
            pair<int,ll> s, ss;
            s = get(res);
            temp = temp + 1ll * s.fi * res - s.se;
            ss = get(1000001);
            ss.fi -= s.fi;
            ss.se -= s.se;
            temp = temp + ss.se - 1ll * ss.fi * res;
            if (temp < ans) {
                ans = temp;
                res_range = {i - k + 1, i};
                med = res;
            }
            ans_trc = res;
        }
    }

    cout << ans << '\n';

    for (int i = res_range.fi; i <= res_range.se; i++) {
        a[i] = med;
    }

    for (int i = 1; i <= n; i++) cout << a[i] << '\n';
    return 0;
}
