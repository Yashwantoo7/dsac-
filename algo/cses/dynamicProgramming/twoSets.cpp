#include <iostream>
#include <bits/stdc++.h>
#define ll long long 

using namespace std;

int mod = (int)1e9 + 7;

void solve(){
    int n;
    cin>>n;
    if((n*(n+1))%4!=0){
        cout<<0<<endl;
        return;
    }
    
    ll dp[n+1][(n*n)];
    dp[0][0]=1;
    for(int i=1;i<=(n*n)/2;i++){
        dp[0][i]=0;
    }
    
    for(int i=1;i<=n;i++){
        for(int x=0;x<=((n*(n+1))/4);x++){
            if(x>=i){
                dp[i][x]=(dp[i-1][x])%mod+(dp[i-1][x-i])%mod;
            }
            else dp[i][x]=dp[i-1][x]%mod;
        }
    }
    cout<<(dp[n][(n*(n+1))/4]*500000004)%mod;
    return;
}

int main()
{
    solve();
    return 0;
}
