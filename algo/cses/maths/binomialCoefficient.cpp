#include<iostream>
#include<bits/stdc++.h>
#define int long long

using namespace std;

int m = (int)1e9 + 7;

int fac[(int)1e6+1],inverseFac[(int)1e6+1];

int modInv(int a,int b){
    int ans = 1;
    while(b){
        if(b&1) ans = (ans*a)%m;
        b=b>>1;
        a=(a*a)%m;
    }
    return ans;
}

void cal(){
    fac[0]=1;
    for(int i=1;i<((int)1e6+1);i++){
        fac[i]=(fac[i-1]*i)%m;
        inverseFac[i] = modInv(fac[i],m-2);
    }
}



int32_t main(){
    cal();
    int t;
    cin>>t;
    while(t--){
        int n,r;
        cin>>n>>r;
        if(n==1){
            cout<<1<<endl;
            return 0;
        }
        int ans = (((fac[n]%m)*(inverseFac[n-r]%m))%m*(inverseFac[r]%m))%m;
        cout<<ans<<endl;
    }
}
