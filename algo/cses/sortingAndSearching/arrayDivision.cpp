#include <iostream>
#include <bits/stdc++.h>
#define int long long

using namespace std;

bool check(int mid,int arr[],int n,int k){
    int sum=0,count=1;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum>mid){
            count++;
            sum=arr[i];
        }
    }
    return count<=k;
}

void solve(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    int mx=0;
    for(int i=0;i<n;i++){cin>>arr[i];mx=max(mx,arr[i]);}
    int ans=mx;
    int l=mx,r=(int)1e18+1;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(check(mid,arr,n,k)){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    cout<<ans;
}

int32_t main()
{
    solve();
   return 0;
}