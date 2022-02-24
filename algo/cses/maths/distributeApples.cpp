#include<iostream>
#include<bits/stdc++.h>
#define int long long
#define N  2000001
using namespace std;

int m = (int)1e9 + 7;


int fac(int x){
    int ans = 1;
    for(int i=1;i<=x;i++){
        ans =(ans*i)%m;
    }
    return ans;
}

int modInv(int a,int b){
    int ans = 1;
    while(b){
        if(b&1) ans = (ans*a)%m;
        b=b>>1;
        a=(a*a)%m;
    }
    return ans;
}

void solve(){
    int n,x;
    cin>>n>>x;
    int ans = ((fac(n+x-1)*modInv(fac(x),m-2)%m)*(modInv(fac(n-1),m-2)))%m;
    cout<<ans%m<<endl;
}
int32_t main()
{
    solve();
   return 0;
}