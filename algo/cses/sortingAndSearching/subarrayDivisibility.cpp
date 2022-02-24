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
    int n;
    cin>>n;
    int arr[n+1];
    int preSum[n+1];
    preSum[0]=0;
    for(int i=1;i<=n;i++){cin>>arr[i];preSum[i]=preSum[i-1]+arr[i];}
    int ans=0;
    map<int,int>mp;
    mp[0]=1;
    for(int i=1;i<=n;i++){
        int r=preSum[i]%n;
        if(r<0)r=r+n;
        if(mp.find(r)!=mp.end()){
            ans+=mp[r];
            mp[r]++;
        }else{
            mp[r]++;
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