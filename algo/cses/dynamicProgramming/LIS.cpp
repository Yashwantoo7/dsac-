
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int getBest(map<int,int>&mp,int v){
    auto it=mp.lower_bound(v);
    if(it==mp.begin())return 0;
    it--;
    return it->second;
}

void insert(map<int,int>&mp,int v,int adv){
    if(mp[v]>=adv){
        return;
    }
    
    mp[v]=adv;
    auto it=mp.find(v);
    it++;
    while(it!=mp.end() && it->second<=adv){
        auto temp=it;
        it++;
        mp.erase(temp);
    }
}

int findLIS(int arr[],int n){
    int dp[n];
    map<int,int>mp;
    mp[arr[0]]=1;
    dp[0]=1;
    for(int i=1;i<n;i++){
        dp[i]=1+getBest(mp,arr[i]);
        insert(mp,arr[i],dp[i]);
    }
    return *max_element(dp,dp+n);
}

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<findLIS(arr,n)<<endl;
}

int main()
{
    solve();
    return 0;
}
