#include<iostream>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
class kpath{
	int n,m,k,A[65][65],dau[65],x[65];
	long d;
	public:
		void input(){
			cin>>n>>k;
			FOR(i,1,n) FOR(j,1,n) A[i][j]=0;
			cin>>m;
			FOR(e,1,m){
				int u,v;
				cin>>u>>v;
				A[u][v]=A[v][u]=1;
			}
		}
		void TRY(int p){
			if(p==k+1){
				d++;
				return;
			}
			FOR(t,1,n)
				if(dau[t]==0 && A[x[p]][t]==1){
					dau[t]=1;
					x[p+1]=t;
					TRY(p+1);
					dau[t]=0;
				}
		}
		void solve(){
			d=0;
			input();
			FOR(i,1,n){
				FOR(j,1,n) dau[j]=0;
				x[1]=i;
				dau[i]=1;
				TRY(1);
			}
			cout<<d/2;
		}
};

signed main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	kpath hmk;
	hmk.solve();
}