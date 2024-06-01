#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    long long  u, v;
    cin >> u >> v;
    int ans = 0;
    long long product;
    product = 1ll * u * v;
    for (long long  i = 1; 1ll * i * i <= product; i++) {
        if (product % i == 0) {
            long long di = product / i;
            if (__gcd(di, i) == u && (((1ll * i * di) / __gcd(di, i)) == v)) ans++;
        }
    }

    cout << ans * 2 << '\n';
    return 0;
}
