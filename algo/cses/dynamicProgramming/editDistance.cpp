#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int dp[5005][5005];

void solve(){
    string a,b;
    cin>>a>>b;
    int n=a.length();
    int m=b.length();
    
    for(int i=0;i<n+1;i++){
        dp[i][0]=i;
    }
    for(int i=0;i<m+1;i++){
        dp[0][i]=i;
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(a[i-1]!=b[j-1])
            dp[i][j]=min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1])+1;
            else{
                dp[i][j]=dp[i-1][j-1];
            }
        }
    }
    cout<<dp[n][m]<<endl;
    
}

int main()
{
    solve();
    return 0;
}
