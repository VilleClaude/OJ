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

int n, k;

int st[N];

void up(int id, int l, int r, int u, int v) {
    if (l > u || r < u) return;
    if (l == r) {
        st[id] = max(st[id], v);
        return;
    }
    int mid = l + r >> 1;
    up(id * 2, l, mid, u, v);
    up(id * 2 + 1, mid + 1, r, u, v);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v) {
    if (l > r) return 0;
    if (l > v || r < u) return 0;
    if (u <= l && r <= v) return st[id];
    int mid = l + r >> 1;
    return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
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

    memset(st, 0, sizeof st);

    cin >> n >> k;
    For (i, 1, n) {
        int a;
        cin >> a;
        int temp = get(1, 1, 100000, a - k, a - 1) + 1;
        up(1, 1, 100000, a, temp);
    }

    cout << get(1, 1, 100000, 1, 100000);

    return 0;
}


