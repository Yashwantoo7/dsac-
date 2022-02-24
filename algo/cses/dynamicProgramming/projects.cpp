#include <iostream>
#include <bits/stdc++.h>
#define pb push_back
#define int long long

using namespace std;

struct projects{
    int st;
    int en;
    int pr;
};

bool cmp(const projects &p1,const projects &p2){
    if(p1.en==p2.en) return p1.st<p2.st;
    return p1.en<p2.en;
}

int findInd(int v,int e,int ind[],int n){
    int l=0,r=e-1;
    int x=-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(ind[mid]<v){
            x=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return x;
}

void solve(){
    int n;
    cin>>n;
    projects arr[n];
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        arr[i].st=a;
        arr[i].en=b;
        arr[i].pr=c;
    }
    sort(arr,arr+n,cmp);
    int dp[n];
    memset(dp,0,sizeof(dp));
    dp[0]=arr[0].pr;
    int ind[n];
    for(int i=0;i<n;i++){
        ind[i]=arr[i].en;
    }
    for(int i=1;i<n;i++){
        int x = findInd(arr[i].st,i,ind,n);
        if(x!=-1)
        dp[i]=max(dp[i-1],arr[i].pr + dp[x]);
        else dp[i]=max(dp[i-1],arr[i].pr);
    }
    cout<<dp[n-1];
}

int32_t main()
{
    solve();
   return 0;
}