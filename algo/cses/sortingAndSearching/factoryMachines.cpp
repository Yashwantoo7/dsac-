#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define vi vector<int>
#define ip pair<int,int>
#define pb push_back
#define ll long long

using namespace std;

bool possible(int t,int mid,int n,int arr[]){
    int pro=0;
    for(int i=0;i<n;i++){
        pro+=(mid/arr[i]);
        if(pro>=t)return true;
    }
    return false;
}


void solve(){
    int n,t;
    cin>>n>>t;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int l=1,r=(int)1e18+1;
    int total=0;
    while(l<=r){
        int mid = l+(r-l)/2;
        if(possible(t,mid,n,arr)){
            total=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    cout<<total<<"\n";
}

int32_t main()
{
    solve();
   return 0;
}