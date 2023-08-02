#include<bits/stdc++.h>
#define ken main()
#define ll long long
using namespace std;
struct TOWER{
	ll x, y, z;
};
TOWER a[305];
ll cmp(TOWER a, TOWER b){
	if (a.x == b.x) return a.y < b.y;
	return a.x < b.x;	
}
ken{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n, x, y, z, stt = 0;	
	while(1){
		stt++;
		cin >> n;
		if(!n) return 0;
		ll dp[305] = {}, j = 0, rs = 0;
		for (ll i = 0; i < n; i++){
			cin >> x >> y >> z;
			a[j].x = x, a[j].y = y, a[j].z = z; j++;
			a[j].x = x, a[j].y = z, a[j].z = y; j++;
			a[j].x = y, a[j].y = x, a[j].z = z; j++;
			a[j].x = y, a[j].y = z, a[j].z = x; j++;
			a[j].x = z, a[j].y = x, a[j].z = y; j++;
			a[j].x = z, a[j].y = y, a[j].z = x; j++;
		}
		n = j;
		sort(a, a + n, cmp);
		for (ll i = 0; i < n; i++) dp[i] = a[i].z, rs = max(rs, dp[i]);
 		for (ll i = 0; i < n; i++){
 			for (ll j = 0; j < i; j++){
 				if (a[j].x < a[i].x && a[j].y < a[i].y){
 					dp[i] = max(dp[i], dp[j] + a[i].z);
 					rs = max(rs, dp[i]);
				}
			}
		}
		cout << "Case " << stt << ": maximum height = " << rs << endl;
	}
}