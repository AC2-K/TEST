#include<bits/stdc++.h>
using namespace std;
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
#define popcount(x) __builtin_popcount(x)
using ll = long long;
//using i128=__int128_t;
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
template<const ll&mod>class modint {
private:
    using mint = modint<mod>;
    ll value = 0;
public:
    modint(ll v = 0) {
        v %= mod;
        if(v < 0)v += mod;
        value = v;
    }
    ll val() {
        return value % mod;
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
        value = val % mod;
        if(value < 0) {
            value += mod;
        }
    }
    void operator+=(mint fp) {
        (value += fp.val()) %= mod;
        if(value < 0) {
            value += mod;
        }
    }
    void operator-=(mint fp) {
        value = value - fp.val();
        value %= mod;
        if(value < 0) {
            value += mod;
        }
    }
    void operator*=(mint fp) {
        value = value * fp.val();
        value = value % mod;
        if(value < 0) {
            value += mod;
        }
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
    friend istream& operator>>(istream& is, mint& mt) {
        ll v;
        is >> v;
        mt = mint(v);
        return is;
    }
    friend ostream& operator << (ostream& os, mint& mt) {
        return os << mt.val();
    }
};
using mint=modint<MOD>;
int main() {
    int n,q;
    cin>>n>>q;
    vector<ll> x(q),y(q),z(q),w(q);
    rep(i,q){
        cin>>x[i]>>y[i]>>z[i]>>w[i];
        x[i]--;
        y[i]--;
        z[i]--;
    }
    //bitごとに分ける

    mint ans=1;
    rep(p,60){
        mint cnt=0;
        rep(msk,1ll<<n){
            vector<int> a(n);
            rep(i,n){
                if(msk&(1ll<<i))a[i]=1;
            }
            bool is_ok=true;
            rep(i,q){
                bool tmp=w[i]&(1ll<<p);
                int r=tmp;

                int l=a[x[i]]|a[y[i]]|a[z[i]];

                if(r!=l){
                    is_ok=false;
                }
            }
            if(is_ok)cnt+=1;
        }

        ans*=cnt;
    }
    cout<<ans<<endl;
}