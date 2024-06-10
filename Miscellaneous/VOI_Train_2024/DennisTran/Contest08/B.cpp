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

int t;
int n, x;
int a[N];

ll po(int a, int b) {
    ll ans = 1;
    for (int i = 1; i <= b; i++) ans = 1ll * ans * a;
        return ans;
}

void solve() {
    cin >> x >> n;
    char c;
    vector<int> pre(n + 3);
    pre[0] = 0;
    a[0] = -1;
    For (i, 1, n) {
        cin >> c;
        a[i] = c - '0';
        pre[i] = pre[i - 1];
        pre[i] += (a[i] > 0);
    }
    ll ans = 0;

    if (n <= 10) {
        for (int i = 1; i <= n; i++) {
            ll temp = 0;
            if (a[i] == 0) ans++;
            else {
                for (int j = i; j <= n; j++) {
                    temp = temp * 10ll + a[j];
                    temp %= x;
                    if (temp == 0) ans++;
                }
            }
        }
    }

    else {
        for (int i = 1; i <= n; i++) {
            int temp = 0;
            if (a[i] == 0) ans++;
            else {
                for (int j = i; j <= min(n, i + 9); j++) {
                    temp = temp * 10 + a[j];
                    temp %= x;
                    if (temp == 0) ans++;
                }
            }
        }

        for (int i = 10; i <= n; i++) {
            int temp = 0;
            for (int j = i - 9; j <= i; j++) {
                temp = temp * 10 + a[j];
                temp %= x;
            }
            if (temp == 0) ans += pre[i - 10];
        }
    }

    cout << ans << '\n';
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

    cin >> t;
    while (t--) solve();

    return 0;
}


