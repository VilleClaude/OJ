#include <bits/stdc++.h>
#define el '\n'
#define fi first
#define sc second
#define int ll
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
using namespace std;
using ll=long long;
using ull=unsigned long long;
using ld=long double;
const int mod=1e9+7;
const int N=1e5+11;
const int lim=1e5;
int n, phi[N];
ll ans[N];
vector<int> uoc[N];
void sang()
{
    for(int i=1;i<=lim;i++) for(int j=i;j<=lim;j+=i) uoc[j].push_back(i);
}
void prepare()
{
    for(int i=1;i<=lim;i++) phi[i]=i;
    for(int i=2;i<=lim;i++)
    {
        if(phi[i]==i)
        {
            for(int j=i;j<=lim;j+=i)
            {
                phi[j]-=phi[j]/i;
            }
        }
    }
}
ll sol(int n)
{
    ll ans=0;
    for(auto x:uoc[n])
    {
        for(auto y:uoc[n])
        {
            ll tmp=x*y;
            if(tmp>n) break;
            if(x!=y && n%(tmp)==0)
            {
                ans+=phi[n/x]*phi[n/y];
            }
        }
    }
    ans/=2;
    for(auto x:uoc[n])
    {
        ll tmp=x*x;
        if(tmp>n) break;
        if(n%(tmp)==0) ans+=phi[n/x]*(phi[n/x]+1)/2;
    }
    return ans;
}
signed main()
{
//    freopen("divisor.INP", "r", stdin);
//    freopen("divisor.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sang();
    prepare();
    for(int i=1;i<=lim;i++) ans[i]=sol(i);
    int t=1;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << ans[n] << el;
    }
}
