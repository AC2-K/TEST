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
const ld eps = ld(0.000000001);
const long double pi = acos(-1);
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
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
    void operator=(mint fp) {
        value = fp.val();
    }
    void operator=(ll val) {
        value = val;
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

    mint inv() {
        return mod_pow(mod - 2);
    }
    mint mod_pow(ll exp) {
        ll base = value;
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
    mint operator/(mint a) {
        return mint(a.inv()*value);
    }
    void operator/=(mint a) {
        value = value * a.inv();
        value %= mod;
    }
};
template<ll T>istream& operator>>(istream& is, modint<T>& mt) {
    ll v;
    is >> v;
    mt = v;
    return is;
}
template<ll T>ostream& operator << (ostream& os, modint<T>& mt) {
    return os << mt.val() % T;
}
int main() {
    int d;
    string k;
    cin>>d>>k;


    using mint=modint<MOD>;
    int n=k.size();
    vector<vector<vector<mint>>> dp(n+1,vector<vector<mint>>(2,vector<mint>(d,0))); //dp[i][flag][j]:=先頭i桁を見る。kとの大小がflagであって、digit sumがmod jなるモノの個数

    dp[0][0][0]=1;
    rep(i,n)rep(is_less,2)rep(j,d){
        int c=k[i]-'0';
        rep(nex,10){
            if(nex>c&&is_less==0)continue;

            int is_less2=is_less;
            if(nex<c)is_less2=1;

            int nj=(j+nex)%d;

            dp[i+1][is_less2][nj]+=dp[i][is_less][j];
        }
    }
    mint ans=dp[n][0][0]+dp[n][1][0]-1;
    cout<<ans<<endl;
}