#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
main(){
        ll n,k1,k2,A[1005],B[1005];
        cin >> n >> k1 >> k2;		
        A[0]=B[0]=1;
        for(int k=1;k<=n;k++){
                A[k]=B[k-1];
                B[k]=0;
                for(int t=k1;t<=k2;t++) if(t>=0&&t<=k) B[k]+=A[k-t];	
        }
        cout << A[n]+B[n];
}