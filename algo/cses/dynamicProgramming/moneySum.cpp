#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int dp[100005];

void solve(){
    int n;
    cin>>n;
    int arr[n];
    int mx=0;
    for(int i=0;i<n;i++){cin>>arr[i];mx=max(arr[i],mx);}
    mx=mx*n+1;
    dp[0]=1;
    for(int i=n-1;i>=0;i--){
        for(int j=mx;j>=0;j--){
            if(j>=arr[i]){
                dp[j]=dp[j]||dp[j-arr[i]];
            }
        }
    }
    vector<int>vec;
    for(int i=1;i<=mx;i++){
        if(dp[i])
        vec.push_back(i);
    }
    cout<<vec.size()<<endl;
    for(int i:vec)cout<<i<<" ";
    cout<<endl;
}

int main()
{
    solve();
    return 0;
}
