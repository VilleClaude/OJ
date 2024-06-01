#include <bits/stdc++.h>

using namespace std;
namespace IO{
    #define getchar() (ipos==iend and (iend=(ipos=_ibuf)+fread(_ibuf,1,__bufsize,stdin),ipos==iend)?EOF:*ipos++)
    #define putchar(ch) (opos==oend?fwrite(_obuf,1,__bufsize,stdout),opos=_obuf:0,*opos++=(ch))
    #define __bufsize (1<<20)
    char _ibuf[__bufsize],_obuf[__bufsize],_stk[20];
    char *ipos=_ibuf,*iend=_ibuf,*opos=_obuf,*oend=_obuf+__bufsize,*stkpos=_stk;
    struct END{~END(){fwrite(_obuf,1,opos-_obuf,stdout);}}__;
    inline void read(int&x){
        register int f=0,ch;
        for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
        for(x=0;isdigit(ch);ch=getchar())x=(x<<3ll)+(x<<1ll)+(ch^48);
        x=f?-x:x;
    }
};

using namespace IO;

unordered_map<int,int> ma;
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int q, x;
    read(q);
    while (q--) {
        read(x);
        int ans = 0;
		if (ma[x] != 0) {
			cout << ma[x] << '\n'; continue;
		}
        for (int i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                ans += 2;
                if (x / i == i) ans--;
            }
        }
		ma[x] = ans;
        cout << ans << '\n';
    }
}
