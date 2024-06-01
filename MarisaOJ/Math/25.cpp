#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    ll n;
    cin >> n;
    if (n == 1) {
        cout << "NO";
        return 0;
    }
    for (int i = 2; 1ll * i * i <= n; i++) {
        if (n % i == 0) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}
