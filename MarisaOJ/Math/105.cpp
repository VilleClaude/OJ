#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 7;
int p[N];

void sieve() {
    for (int i = 1; i <= N - 7; i++) p[i] = i;
    for (int i = 2; i * i <= N - 7; i++) {
        if (p[i] == i) {
            for (int j = i * i; j <= N - 7; j += i) {
                if (p[j] == j) p[j] = i;
            }
        }
    }
}

int cnt[N];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, a;
    memset(cnt, 0, sizeof cnt);
    cin >> n;
    sieve();
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        int rem = 1;
        int cur = p[a];
        while (cur != 1) {
            int count = 0;
            while (a % cur == 0) count++, a /= cur;
            if (count % 2 == 1) rem *= cur;
            cur = p[a];
        }
        ans += cnt[rem];
        cnt[rem]++;
    }

    cout << ans << '\n';
    return 0;
}
