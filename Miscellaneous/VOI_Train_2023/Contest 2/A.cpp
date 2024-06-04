#include <bits/stdc++.h>

using namespace std;

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
    
    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        int mx = -1;
        int mi = 1e7;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') mx = max(mx, i);
            if (s[i] == '1') mi = min(mi, i);
        }
        int ans = 0;
        for (int i = mi; i <= mx; i++) {
            if (s[i] == '0') ans++;
        }
        if (mx < mi) {
            cout << "-1\n";
        }
        else cout << ans << '\n';
    }
    return 0;
}
