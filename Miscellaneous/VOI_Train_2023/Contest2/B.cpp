#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 7;
#define ll long long 

int n;
priority_queue<int> qmax;
priority_queue<int, vector<int>, greater<int>> qmin;
ll ans, sum, a[N], ma[N], mi[N];

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
    for (int i = 1; i <= n * 3; i++) {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++) {
        sum += a[i];
        qmin.push(a[i]);
    }
    for (int i = n; i <= 2 * n; i++) {
        sum += a[i];
        qmin.push(a[i]);
        if (qmin.size() > n) {
            sum -= qmin.top();
            qmin.pop();
        }
        ma[i] = max(ma[i - 1], sum);
    } 

    sum = 0;
    for (int i = n * 3; i > 2 * n + 1; i--) {
        sum += a[i];
        mi[i] = 1e18;
        qmax.push(a[i]);
    }

    for (int i = 2 * n + 1; i >= n; i--) {
        sum += a[i];
        qmax.push(a[i]);
        if (qmax.size() > n) {
            sum -= qmax.top();
            qmax.pop();
        }
        mi[i] = min(sum, mi[i + 1]);
    }

    ans = -1e18;
    for (int i = n; i <= n * 2; i++) {
        ans = max(ans, ma[i] - mi[i + 1]);
    }

    cout << ans << '\n';
    return 0;
}
