#include <bits/stdc++.h>

using namespace std;
#define fi first
#define se second
#define ii pair<int,int>
int n;
ii a[1000000];

bool check(int x) {
    vector<int> can, v;
    for (int i = 1; i <= n; i++) {
        if (a[i].fi >= x) {
            can.push_back(a[i].fi - x + a[i].se);
        }
        else v.push_back(a[i].se);
    }
    sort(can.begin(), can.end());
    sort(v.begin(), v.end());
    int i = 0;
    int m = can.size();
    if (can.size() < v.size()) return 0;
    for (auto x: v) {
        if (i >= m) return 0;
        while (i + 1 < m && can[i] < x) i++;
        if (can[i] < x) return 0;
        else i++;
    }
    return 1;
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

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
    }

    int l = 1;
    int r = 1e9;
    int res = -1;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    cout << res << '\n';
    return 0;
}
