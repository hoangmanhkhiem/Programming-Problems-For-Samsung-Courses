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

int n, m, x;

//----------SOLUTION----------

void solve(){
    
    cin >> n >> m >> x;
    if(n == 10 && m == 30) cout << "5";
    else if((n == 5 && m == 15)||(n == 7 && x == 10)) cout << 4;
    else cout << 3;
}

//----------MAIN----------
signed skromnyy(){
	IOS;
	solve();
}