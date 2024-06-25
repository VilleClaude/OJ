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
const int  N = 2e6+7;
const int M = 1e9+7;
const ll oo = 3e18;
int n;
int p[N], s[N];

void sieve() {
    memset(p, 0, sizeof p);
    p[0] = p[1] = 1;
    for (int i = 2; i * i <= N - 7; i++) {
        if (!p[i]) {
            for (int j = i * i; j <= N - 7; j += i) p[j] = 1;
        }
    }
    s[0] = s[1] = 0;
    for (int i = 2; i <= N - 7; i++) {
        s[i] = s[i - 1];
        if (p[i] == 0) s[i]++;
    }
}

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
    sieve();
    int t;

    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll ans = 1ll * n * (n - 1ll) * (n - 2ll);
        ans /= 6ll;
        ll res = 0;
        for (int i = 1; i <= n; i++) {
            ll xanh = s[i + n] - s[i];
            ll red = n - xanh;
            if (i == 1) xanh -= 1;
            else red -= 1;
            res = res + xanh * red;
        }

        cout << ans - res / 2 << '\n';
    }


    return 0;
}
