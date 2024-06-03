#include <bits/stdc++.h>
#pragma GCC target("popcnt")
using namespace std;
#define ll long long 
int n;
bitset<3001> b[3002];

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
    ll ans = 0;

    for (int i = 0; i < n; i++) cin >> b[i];

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            bitset<3001> temp = (b[i] & b[j]);
            int x = temp.count();
            ans = ans + x * (x - 1) / 2;
        }
    }

    cout << ans << '\n';
    
    return 0;
}
