#include <iostream>
#include <bits/stdc++.h>
#define ll long long 
 
using namespace std;
 
int mod=(int)1e9 +7;
 
ll dp[100001];
int pages[1001];
int cost[1001];
 
void solve(){
    int n,x;
    cin>>n>>x;
    for(int i=0;i<n;i++)cin>>cost[i];
    int pages[n];
    for(int i=0;i<n;i++)cin>>pages[i];
    for(int i=0;i<n;i++){
        for(int j=x;j>=cost[i];j--){
            dp[j]=max(dp[j],dp[j-cost[i]]+pages[i]);
        }
    }
    cout<<dp[x]<<endl;
}
 
int main()
{
    solve();
    return 0;
}