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
const int  N = 2e5+7;
const int M = 998244353;
const ll oo = 3e18;

string s;
int n;
int cnt[N][4];

ll dp[N];

struct BIT {
    vector<int> bit, id;

    void clr() {
        bit.clear();
        id.clear();
        id.push_back(-M);
    }
    void pre() {
        sort(all(id));
        RRH(id);
        bit.resize(id.size() + 3);
    }

    int get_pos(int x) {
        int l = 1;
        int r = id.size() - 1;
        int res = 0;
        while (l <= r) {
            int m = l + r >> 1;
            if (id[m] >= x) {
                res = m;
                r = m - 1;
            }
            else l = m + 1;
        }
        return res;
    }

    void up(int x, ll val) {
        if (x < 1) return;
        for (;x < bit.size(); x += x& - x) bit[x] += val, bit[x] %= M;
    }
    
    ll get(int x) {
        ll ans = 0;
        for (; x > 0; x -= x& - x) {
            ans += bit[x];
        }
        return ans;
    }
} I[N], C[N], P[N];

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

    cin >> s;
    n = s.size();
    s = " " + s;

    memset(cnt, 0, sizeof cnt);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 3; j++) cnt[i][j] = cnt[i - 1][j];
        if (s[i] == 'I') cnt[i][1]++;
        if (s[i] == 'C') cnt[i][2]++; 
        if (s[i] == 'P') cnt[i][3]++;
    }

    memset(dp, 0, sizeof dp);
    dp[0] = 1;

    For (i, 0, 200003) {
        I[i].clr();
        C[i].clr();
        P[i].clr();
    }

    For (i, 0, n) {
        int k = cnt[i][2] - cnt[i][3] + 100000;
        I[k].id.push_back(cnt[i][1] - cnt[i][2]);
        k = cnt[i][1] - cnt[i][3] + 100000;
        C[k].id.push_back(cnt[i][2] - cnt[i][1]);
        k = cnt[i][1] - cnt[i][2] + 100000;
        P[k].id.push_back(cnt[i][3] - cnt[i][1]);
    }

    For (i, 0, 200000) {
        I[i].pre();
        C[i].pre();
        P[i].pre();
    }

    int pos = I[100000].get_pos(0);
    I[100000].up(pos, 1);
    pos = C[100000].get_pos(0);
    C[100000].up(pos, 1);
    pos = P[100000].get_pos(0);
    P[100000].up(pos, 1);

    For (i, 1, n) {
        int k1 = cnt[i][2] - cnt[i][3] + 100000;
        int pos1 = I[k1].get_pos(cnt[i][1] - cnt[i][2]);
        dp[i] += I[k1].get(pos1 - 1);
        int k2 = cnt[i][1] - cnt[i][3] + 100000;
        int pos2 = C[k2].get_pos(cnt[i][2] - cnt[i][1]);
        dp[i] += C[k2].get(pos2 - 1);
        int k3 = cnt[i][1] - cnt[i][2] + 100000;
        int pos3 = P[k3].get_pos(cnt[i][3] - cnt[i][1]);
        dp[i] += P[k3].get(pos3 - 1);
        dp[i] %= M;
        I[k1].up(pos1, dp[i]);
        C[k2].up(pos2, dp[i]);
        P[k3].up(pos3, dp[i]);
    }

    cout << dp[n] << '\n';

    return 0;
}


