#include<bits/stdc++.h>
using namespace std;
#define int long long int
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,l1,l2;cin >> n >> l1 >> l2;
    int arr[n];
    for (int &x:arr)cin >> x;
    int i=0,cur=0,ans=LONG_LONG_MIN;
    for (int j=0;j<n;j++){
        cur+=arr[j];
        if (j-i+1>l2) cur-=arr[i++];
        while (i<=j && j-i+1>=l1 && cur-arr[i]>=cur) cur-=arr[i++];
        if (j-i+1>=l1) ans=max(ans,cur);
    }
    cout << ans;
}