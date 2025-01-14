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
const int INF = 1e9;
const ll INFL = 1e18;
const ld eps = ld(0.000000001);
const long double pi = 3.141592653589793;
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
/*
template<class T>using v=vector<T>;
template<class T>using vv=v<v<T>>;
template<class T>using vvv=v<vv<T>>;
template<class T>using vvvv=v<vvv<T>>;
*/
template<class T>void chmax(T&x,T y){if(x<y)x=y;}
template<class T>void chmin(T&x,T y){if(x>y)x=y;}

template<ll mod>class modint {
private:
    using mint = modint<mod>;
    ll value = 0;
public:

    modint(ll v = 0) {
        v %= mod;
        v = (v + mod) % mod;
        value = v;
    }
    ll val() {
        return value;
    }
    mint operator+(mint fp) {
        return mint(value + fp.val());
    }
    mint operator-(mint fp) {
        return mint(value - fp.val());
    }
    mint operator*(mint fp) {
        return mint(value * fp.val());
    }

    void operator+=(mint fp) {
        value = ((value + fp.val() + mod) % mod + mod) % mod;
    }
    void operator-=(mint fp) {
        value = value - fp.val();
        value %= mod;
        value += mod;
        value %= mod;
    }
    void operator*=(mint fp) {
        value = value * fp.val();
        value = (value % mod + mod) % mod;
    }
    bool operator==(mint fp) {
        return value == fp.val();
    }
    bool operator<(mint fp) {
        return value < fp.val();
    }
    bool operator>(mint fp) {
        return value > fp.val();
    }
    bool operator<=(mint fp) {
        return value <= fp.val();
    }
    bool operator>=(mint fp) {
        return value >= fp.val();
    }

    ll inv() {
        return mod_pow(mod - 2);
    }
    ll mod_pow(ll exp) {
        if (exp < 0)exp += (mod - 1);
        if (exp == 0)return 1;
        if (exp == 1)return value;
        ll ret = mod_pow(exp / 2);
        return ret * ret % mod * mod_pow(exp % 2)%mod;
    }
    mint operator/(mint a) {
        return mint(value * a.inv());
    }
    void operator/=(mint a) {
        value = value * a.inv();
        value%=mod;
    }
};
template<ll T>istream& operator>>(istream& is, modint<T>& mt) {
    ll v;
    is >> v;
    mt = v;
    return is;
}
template<ll T>ostream& operator << (ostream& os, modint<T>& mt) {
    return os << mt.val()%T;
}
using mint=modint<MOD2>;
int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto&aa:a)cin>>aa;
    const int K_MAX=9;
    vector<vector<mint>> dp(n+1,vector<mint>(K_MAX+1,0));
    //先頭i項を見る
    //先頭がjとなるようにする方法の数
    dp[1][a[0]]=1;
    const int mod=10;
    for(int i=1;i<n;i++)for(int j=0;j<=K_MAX;j++){
        dp[i+1][(j+a[i])%mod]+=dp[i][j];
        dp[i+1][(j%mod*a[i]%mod)%mod]+=dp[i][j];
    }
    rep(k,K_MAX+1){
        cout<<dp[n][k]<<endl;
    }
}