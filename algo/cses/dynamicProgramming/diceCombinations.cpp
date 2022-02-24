/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9+7)

using namespace std;

void solve(){
    int n;
    cin>>n;
    ll dp[n+1];
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=0;
        for(int j=1;j<=6 && j<=i;j++){
            dp[i]+=(dp[i-j]%mod);
        }
    }
    cout<<(dp[n]%mod)<<endl;
}

int main()
{
    solve();

    return 0;
}
