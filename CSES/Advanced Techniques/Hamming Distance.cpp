#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e4;

int N, ans, b[maxN];

int read(){
    char c;
    int res = 0;
    while((c = getchar()) != '\n'){
        res <<= 1;
        res += (c-'0')&1;
    }
    return res;
}

int main(){
    cin >> N >> ans;
    for(int i = 0; i < N; i++)
        b[i] = read();

    for(int i = 0; i < N; i++)
        for(int j = i + 1; j < N; j++)
            ans = min(ans, __builtin_popcount(b[i]^b[j]));

    cout << ans << '\n';
}
