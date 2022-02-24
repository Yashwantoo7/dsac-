#include <iostream>
#include <bits/stdc++.h>
#define ll long long 

using namespace std;

ll dp[5001][5001];

ll game(int i,int j,int n,ll arr[]){
    if(i>j)return 0;
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    return dp[i][j]=max(arr[i]+min(game(i+2,j,n,arr),game(i+1,j-1,n,arr)),arr[j]+min(game(i+1,j-1,n,arr),game(i,j-2,n,arr)));
}

void solve(){
    int n;
    cin>>n;
    ll arr[n];
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)cin>>arr[i];
    cout<<game(0,n-1,n,arr)<<endl;
    // int row=n;
    // int col=0;
    // int r=0,c=0;
    // while(row>=0){
    //     r=0;
    //     c=col;
    //     while(r<row){
    //         if(r==c){
    //             dp[r][c]=arr[r];
    //         }
    //         else if(abs(r-c)==1){
    //             dp[r][c]=max(arr[r],arr[c]);
    //         }
    //         else{
    //             dp[r][c]=max(arr[r]+min(dp[r+2][c],dp[r+1][c-1]),arr[c]+min(dp[r+1][c-1],dp[r][c-2]));
    //         }
    //         r++;
    //         c++;
    //     }
    //     row--;
    //     col++;
    // }
    // // for(int i=0;i<n;i++){
    // //     for(int j=0;j<n;j++){
    // //         cout<<dp[i][j]<<" ";
    // //     }cout<<endl;
    // // }
    // cout<<dp[0][n-1]<<endl;
}

int main()
{
    solve();
    return 0;
}
