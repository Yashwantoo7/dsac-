/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int mod=1e9+7;

void solve(){
    int n,x;
    cin>>n>>x;
    ll dp[x+1];
    dp[0]=0;
    int coins[n];
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
   for(int i=1;i<=x;i++){
        dp[i]=1e6+1
        for(int j=0;j<n;j++){
            if(coins[j]<=i){
                dp[i]=min(dp[i],dp[i-coins[j]]+1);
            }
        }
    }
    cout<<dp[x];
}

int main()
{
    solve();

    return 0;
}
