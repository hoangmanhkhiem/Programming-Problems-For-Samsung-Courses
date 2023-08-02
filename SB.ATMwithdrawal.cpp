#include<bits/stdc++.h>
#define ken main()
#define ll long long
using namespace std;
ll N[]={0,1,1,1,2,1,2,2,2,3};
ll S[]={1,1,1,1,2,1,2,1,1,3};
void Doi_tien(ll W,ll c,ll &n,ll &s){
	if(W<10){
		n+=N[W];
		s*=S[W];
		return;
	}
	if(c==0){
		ll K=W%5+5;
		W=W-K;
		n+=W/5+N[K];
		s*=S[K];
		return;
	}
	n+=N[W%10];
	s*=S[W%10];
	Doi_tien(W/10,c-1,n,s);
}
void sol(){
	ll W,n=0,s=1;
	ll c;
	cin >> W >> c;
	if(W%1000){
		cout << "0\n";
		return;
	}
	Doi_tien(W/1000,c,n,s);
	cout << n << " " << s<<"\n";
}
ken{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n; cin >> n;
	while(n--) sol();
}