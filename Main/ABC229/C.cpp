#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
//#include<atcoder/all>
//using namespace atcoder;
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;
using P = pair<int, int>;
const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1e9 + 7;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
int main() {
    int N,W;
    cin>>N>>W;
    vector<P> cheese(N);
    rep(i,N)cin>>cheese[i].first>>cheese[i].second;
    sort(all(cheese),greater<>());
    ll val=0;
    rep(i,N){
        ll vol=min(W,cheese[i].second);
        val+=cheese[i].first*vol*1ll;

        W-=vol;
        if(W<=0){
            cout<<val<<endl;
            return 0;
        }
    }
    cout<<val<<endl;
    return 0;
}