#include<iostream>
#include<bits/stdc++.h>
#define int long long
#define N  2000001
using namespace std;

int m = (int)1e9 + 7;

int dp[1000000];

int fun(int n){
    if(n==1)return 0;
    if(n==2)return 1;
    if(dp[n])return dp[n];
    return dp[n]=((n-1)*(fun(n-2)%m+fun(n-1)%m))%m;
}

void solve(){
    int n;
    cin>>n;
    memset(dp,0,sizeof(dp));
    cout<< fun(n)<<endl;
}
int32_t main()
{
    solve();
   return 0;
}