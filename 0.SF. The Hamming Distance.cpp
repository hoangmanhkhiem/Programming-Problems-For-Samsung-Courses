#include<bits/stdc++.h>
using namespace std;
int main(){
    int test;
    cin>>test;
    while(test--){
                  int N, zero, ones;
                  cin>>N>>ones;
                  int arr[N], i;
                  for(i=0; i<N-ones; i++) arr[i]=0;
                  for(i=N-ones; i<N; i++) arr[i]=1;
                  do{
                           for(i=0; i<N; i++) cout<<arr[i];
                           cout<<endl;
                  }while(next_permutation(arr, arr+N));
                  if(test > 0) cout<<endl;
    }
}