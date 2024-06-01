#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 7;
#define ll long long 
int n;
ll cnt[N], ans[N];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    memset(cnt, 0, sizeof cnt);

    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        cnt[a]++;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i * 2; j <= n; j += i) cnt[i] += cnt[j];
    }

    for (int i = n; i >= 1; i--) {
        ans[i] = (cnt[i] - 1) * cnt[i] / 2ll;
        for (int j = i * 2; j <= n; j += i) ans[i] -= ans[j];
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    return 0;
}
