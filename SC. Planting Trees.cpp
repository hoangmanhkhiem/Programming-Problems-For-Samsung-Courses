#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, a[100005];
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a, a+n, greater<int>());
    int kq=0;
    for(int i=0; i<n; i++){
        if(i+a[i]>kq)
        {
            kq=a[i]+i;
        }
    }
    cout << kq+2;
}