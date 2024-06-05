#include <bits/stdc++.h>

using namespace std;

int n, a[1000000];

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
    int ans = 1e9;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ans = min(a[i], ans);
    }

    for (int i = 1; i <= n; i++) 
    {
        if (a[i] > ans) {
            if (a[i] / 2 < ans) ans /= 2;
        }
    }

    cout << ans << '\n';
    return 0;
}
