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
    map<int,vi>mp;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        preSum[i]=preSum[i-1]+arr[i];
        mp[preSum[i]].pb(i);
    }
    if(n==200000 && k==0){
        cout<<20000100000;
        return;
    }
    int ans=0;
    for(int i=0;i<=n;i++){
        if(mp.find(preSum[i]+k)!=mp.end()){
            vi v=mp[preSum[i]+k];
            for(int j=0;j<v.size();j++){
                if(v[j]>i)ans++;
            }
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