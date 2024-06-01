#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 7;
#define fi first
#define se second
int n;
pair<int,int> a[N];
vector<int> v;

struct BIT {
    int bit[N];
    BIT() {memset(bit, 0, sizeof bit);}

    void up(int x, int val) {
        for (; x < N - 7; x += x& - x) bit[x] += val;
    }

    int get(int x) {
        int ans = 0;
        for (; x > 0; x -= x& -x) ans += bit[x];
        return ans;
    }
} T, T1;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].fi, v.push_back(a[i].fi);
    for (int i = 1; i <= n; i++) cin >> a[i].se, v.push_back(a[i].se);

    sort(v.begin(), v.end());
    for (int i = 1; i <= n; i++) {
        int j = lower_bound(v.begin(), v.end(), a[i].fi) - v.begin() + 1;
        a[i].fi = j;
        T.up(j, 1);
        j = lower_bound(v.begin(), v.end(), a[i].se) - v.begin() + 1;
        a[i].se = j;
    }

    sort (a + 1, a + n + 1, [](pair<int,int> a, pair<int,int> b) {
        if (a.fi == b.fi) return a.se < b.se;
        return a.fi < b.fi;
    });

    int mx = -1, cnt = 1;
    for (int i = n; i >= 1; i--) {
        int temp = T.get(a[i].fi - 1);
        temp += T1.get(a[i].se - 1);
        if (temp > mx) cnt = 1, mx = temp;
        else {
            if (temp == mx) cnt++;
        }
        T1.up(a[i].se, 1);
       // cout << temp << '\n';
    }

    cout << cnt << '\n';

    return 0;
}
