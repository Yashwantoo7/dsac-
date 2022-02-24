/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int mx(int n){
    int x=0;
    while(n>0){
        x=max(x,n%10);
        n=n/10;
    }
    return x;
}

void solve(){
    int n;
    cin>>n;
    int dp[n+1];
    for(int i=0;i<n+1;i++){
        if(i<=9){dp[i]=1;continue;}
        dp[i]=dp[i-mx(i)]+1;
    }
    cout<<dp[n];
}

int main()
{
    solve();
    return 0;
}
