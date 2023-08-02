#include<bits/stdc++.h>
using namespace std;
int main(){
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        int T,N,F;
        cin >>T;
        while(T--){
                        cin >> N >> F;
                        int r[N];
                        for(int i = 0;i < N;++i){
                                cin >> r[i];
                                r[i] *= r[i];
                        }
                        sort(r,r + N);
                        double lo = 0,hi = 4e8,mi;
                        for(int it = 0;it < 43;++it){
                                mi = (lo + hi) / 2;
                                int cont = 0;
                                for(int i = N - 1;i >= 0 && cont <= F;--i)
                                        cont += (int)floor(M_PI * r[i] / mi);
                                if(cont > F) lo = mi;
                                else hi = mi;
                        }
                        cout << fixed << setprecision(4)<<lo<<"\n";
        }
}