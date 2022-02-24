#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define vi vector<int>
#define ip pair<int,int>
#define pb push_back
#define ll long long

using namespace std;

bool cmp(const ip &p1,const ip &p2){
    return p1.first<p2.first;
}

void solve(){
    int n,k;
    cin>>n>>k;
    int arr[n+1];
    arr[0]=0;
    int preSum[n+1];
    preSum[0]=0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        preSum[i]=preSum[i-1]+arr[i];
    }
    int ans=0;
    int i=1,j=0;
    while(i<=n){
        if(i==j){
            if(preSum[i]==k){ans++;continue;}
            else if(preSum[i]<k){i++;continue;}
            else {i++;j++;continue;}
        }
        if(preSum[i]-preSum[j]>k){
            j++;continue;
        }
        if(preSum[i]-preSum[j]<k){
            i++;continue;
        }
        else{
            i++;j++;ans++;
        }
    }
    cout<<ans;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
   return 0;
}