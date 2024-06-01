#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a, b;
    cin >> a >> b;
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            for (int k = 1; k <= 6; k++) {
                for (int h = 1; h <= 6; h++) {
                    int red, blue;
                    red = blue = 0;
                    if (i == 1 || i == 4) red += i;
                    else blue += i;
                    if (j == 1 || j == 4) red += j;
                    else blue += j;
                    if (h == 1 || h == 4) red += h;
                    else blue += h;
                    if (k == 1 || k == 4) red += k;
                    else blue += k;
                    if (red == a && blue == b) {
                        cout << "Yes";
                        return 0;
                    }
                }
            }
        }
    }

    cout << "No";
    return 0;
}
