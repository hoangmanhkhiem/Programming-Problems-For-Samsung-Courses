//----------HEADER----------
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
//----------TEMPLATES----------
template<typename... T>
void in(T&... args) { ((cin >> args), ...);}
template<typename... T>
void out(T&&... args) { ((cout << args << ' '), ...);}
template<typename... T>
void outl(T&&... args) { ((cout << args << ' '), ...); cout<<endl;}
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {cerr << *it << '=' << a << ', '; err(++it, args...);}
//----------MACROS----------
#define skromnyy main
#define int long long
#define pb push_back
#define F first
#define S second
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define vc vector
#define nl cout<<endl
#define E cerr<<endl
#define all(x) x.begin(),x.end()
#define FOR(i,a,b) for (int i=a; i<b; ++i)
#define FOV(i,a,b) for (int i=a; i>b; --i)
#define IOS ios_base::sync_with_stdio(false)
#define setpr(x) cout<<setprecision(x)<<fixed
#define sz size()
#define inFOV(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define inv(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define ins(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
//----------CONSTANTS----------
const ll inf = INT_MAX;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll mod = 1000000007;
//----------GLOBALS----------

int H, W, N, res = 0, h[13] = { }, w[13] = { }, busy[31][31] = { };

//----------SOLUTION----------
bool check(int i, int j, int k) {
	FOR(u,i,i + w[k])
		FOR(v,j,j + h[k])
			if (busy[u][v]) return false;
	return true;
}
void mark(int i, int j, int k, int val) {
	FOR(u,i,i + w[k]) FOR(v,j,j + h[k]) busy[u][v] = val;
}
void TRY(int k) {
	if (res) return;
	FOR(i,0,W - w[k]+1)
		FOR(j,0,H - h[k]+1) {
			if (check(i, j, k)) {
				//neu co the dat hcn thu k tai vi tri i,j
				mark(i, j, k, 1); //danh dau tat ca vung nay bang 1
				if (k == N) res = 1;
				else TRY(k + 1);
				mark(i, j, k, 0);
			}
		}
}
void initialize() {
	in(H,W,N);
	FOR(i,1,N+1) in(h[i],w[i]);
}
void solve(){
	initialize();
	TRY(1);
	out(res);
}
//----------MAIN----------
signed skromnyy(){
    IOS;
    solve();
}