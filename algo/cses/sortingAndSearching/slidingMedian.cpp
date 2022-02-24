#include <iostream>
#include <bits/stdc++.h>
#define pb push_back
#define int long long

using namespace std;


void solve(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    set<pair<int,int>>leftSet;
    set<pair<int,int>>rightSet;
    if(k==1){
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        return;
    }
    if(k==2){
        for(int i=1;i<n;i++){
            cout<<min(arr[i-1],arr[i])<<" ";
        }
        return;
    }
    vector<pair<int,int>>vec;
    for(int i=0;i<k;i++){
        vec.pb({arr[i],i});
    }
    sort(vec.begin(),vec.end());
    for(int i=0;i<k/2 + (k%2);i++){
        leftSet.insert(vec[i]);
    }
    for(int i=k/2 + (k%2);i<k;i++){
        rightSet.insert(vec[i]);
    }
    auto t=leftSet.rbegin();
    cout<<t->first<<" ";
    for(int i=1;i<n-k+1;i++){
        if(leftSet.find({arr[i-1],i-1})!=leftSet.end())
            leftSet.erase({arr[i-1],i-1});
        else
            rightSet.erase({arr[i-1],i-1});
        if((leftSet.rbegin()->first)<arr[i+k-1]){
            rightSet.insert({arr[i+k-1],i+k-1});
        }
        else
            leftSet.insert({arr[i+k-1],i+k-1});
            
        while(leftSet.size()<k/2 +(k%2)){
            pair<int,int> p = *rightSet.begin();
            leftSet.insert(p);
            rightSet.erase(p);
        }
        while(leftSet.size()>k/2 +(k%2)){
            pair<int,int>p = *leftSet.rbegin();
            rightSet.insert(p);
            leftSet.erase(p);
        }
        cout<<leftSet.rbegin()->first<<" ";
    }
}

int32_t main()
{
    solve();
   return 0;
}