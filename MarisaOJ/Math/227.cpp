#include <bits/stdc++.h>

using namespace std;

#define ll long long 
ll n, l, r;

inline ll get_num(ll l, ll r, ll x) {
    ll lo = (l / x) * x;
    if (lo < l) lo += x;
    ll hi = (r / x) * x;
    return (hi - lo) / x + 1;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int q;
    cin >> n >> q;
    vector<ll> prime;
    for (int i = 2; i <= 1000000; i++) {
        bool ok = 0;
        while (n % i == 0) {
            n /= i;
            ok = 1;
        }
        if (ok) prime.push_back(i);
    }

    if (n > 1) prime.push_back(n);

    vector<ll> add, sub;
    ll sz = prime.size();
    for (int mask = 1; mask < (1ll << sz); mask++) {
        ll num = 1;
        int cnt = 0;
        for (int i = 0; i < sz; i++) {
            if (mask & (1ll << i)) {
                cnt++;
                num *= prime[i];
            }
        }
        if (cnt & 1) add.push_back(num);
        else sub.push_back(num);
    }

    while (q--) {
        ll ans = 0;
        cin >> l >> r;
        for (auto num: add) ans += get_num(l, r, num);
        for (auto num: sub) ans -= get_num(l, r, num);
        cout << (r - l + 1) - ans << '\n';
    }
    return 0;
}
