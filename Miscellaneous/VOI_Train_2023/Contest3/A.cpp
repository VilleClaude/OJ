#include <bits/stdc++.h>

using namespace std;
string s;
int sum = 0;

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
    int cnt1, cnt2;
    cnt1 = cnt2 = 0;

    cin >> s;
    for (char c: s) {
        int num = c - '0';
        sum += num;
        if (num % 3 == 1) cnt1++;
        if (num % 3 == 2) cnt2++;
    }

    if (sum % 3 == 0) {cout << 0 << '\n'; return 0;}
    if (sum % 3 == 1) {
        if (cnt1 > 0) {
            cout << 1 << '\n';
            return 0;
        }
        if (cnt2 >= 2) {
            cout << 2 << '\n';
            return 0;
        }
        cout << s.size() << '\n';
        return 0;
    }
    if (sum % 3 == 2) {
        if (cnt2 > 0) {
            cout << 1 << '\n';
            return 0;
        }
        if (cnt1 >= 2) {
            cout << 2 << '\n';
            return 0;
        }
        cout << s.size() << '\n';
        return 0;
    }

    return 0;
}
