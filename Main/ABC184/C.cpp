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
int main() {
    int r1,c1,r2,c2;
    cin>>r1>>c1>>r2>>c2;
    int dx=r1-r2;
    int dy=c1-c2;
    int ans=3;
    if(dx==0&&dy==0)ans=0;
    else if(dx==dy||dx==-dy||abs(dx)+abs(dy)<=3)ans=1;
    else if(abs(dx)%2==abs(dy)%2||abs(dx+dy)<=3||abs(dx-dy)<=3||abs(dx)+abs(dy)<=6)ans=2;
    cout<<ans<<endl;
}