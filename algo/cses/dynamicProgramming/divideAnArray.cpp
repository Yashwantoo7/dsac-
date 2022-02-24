Given an array arr[] and an integer K. The task is to divide the array into K parts ( subarray ) such that the sum of the values of all subarray is minimum.
The value of every subarray is defined as: 
 

Take the maximum from that subarray.
Subtract each element of the subarray with the maximum.
Take the sum of all the values after subtraction.


#include <iostream>
#include <bits/stdc++.h>
#define int long long

using namespace std;


int X=0;

int dp[1001][1001];

void solve(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        X+=arr[i];
    }
    k--;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=k;j++){
            dp[i][j]=X;
            int mx=-1,sum=0;
            
            for(int l=i;l<n;l++){
                mx=max(mx,arr[l]);
                sum+=arr[l];
                int diff = mx*(l-i+1)-sum;
                if(j==0){
                    dp[i][j]=diff;
                }
                else{
                    dp[i][j] = min(dp[i][j],diff+dp[l+1][j-1]);
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=k;j++)cout<<dp[i][j]<<" ";
        cout<<"\n";
    }cout<<"\n";
    cout<<dp[0][k];
}

int32_t main()
{
    solve();
   return 0;
}