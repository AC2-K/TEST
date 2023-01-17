#include<bits/stdc++.h>
using namespace std;
//cout << fixed << setprecision(10);
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
#define popcount(x) __builtin_popcount(x)
using ll = long long;
using ld = long double;
using graph = vector<vector<int>>;
using P = pair<int, int>;
const int inf = 1e9;
const ll infl = 1e18;
const ld eps = 1e-6;
const long double pi = acos(-1);
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
template<class T>void chmax(T&x,T y){if(x<y)x=y;}
template<class T>void chmin(T&x,T y){if(x>y)x=y;}
ll mod_pow(ll base, ll exp, ll mod) {
    if(base==0)return 0;
    ll ans = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) {
            ans *= base;
            ans %= mod;
        }
        base *= base;
        base %= mod;
        exp >>= 1;
    }
    return ans;
}
ll mod_inv(ll val){
    val%=MOD;
    return mod_pow(val,MOD-2,MOD);
}
int main() {
    int n,p;
    cin>>n>>p;
    map<ll,ll> cnt;
    rep(i,n){
        ll a;
        cin>>a;
        a%=MOD;
        cnt[a]++;
    }
    if(p==0){
        ll ans=0;
        for(auto el:cnt){
            if(el.first==0)continue;
            ans+=el.second;
        }
        ans*=cnt[0];
        ans+=(cnt[0]*(cnt[0]-1))/2;
        cout<<ans<<endl;
        return 0;
    }
    ll ans=0;
    for(auto el:cnt){
        int v=el.first;
        int u=(mod_inv(v)*p)%MOD;
        if(v==u){
            ans+=el.second*(el.second-1);
        }else{
            ans+=cnt[v]*cnt[u];
        }
    }
    cout<<ans/2<<endl;
}