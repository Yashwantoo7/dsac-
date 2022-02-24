#include <iostream>
#include <bits/stdc++.h>
#define int long long

using namespace std;

int sumSt(int st[],int arr[],int si,int sl,int sr,int l,int r){
    if(l<=sl && r>=sr){
        return st[si];
    }
    if(l>sr || sl>r){
        return 0;
    }
    int mid = sl+(sr-sl)/2;
    return sumSt(st,arr,2*si+1,sl,mid,l,r)^sumSt(st,arr,2*si+2,mid+1,sr,l,r);
}


void updateSt(int st[],int si,int sl,int sr,int l,int r,int val){
    if(l>sr || sl>r)return;
    if(sl>=l && sr<=r)st[si]+=val;
    if(sl!=sr){
        int mid=sl+(sr-sl)/2;
        updateSt(st,2*si+1,sl,mid,l,r,val);
        updateSt(st,2*si+2,mid+1,sr,l,r,val);
    }
    return;
}


void solve(){
    int n,q;
    cin>>n>>q;
    int arr[n];
    int st[4*(n)]={0};
    for(int i=0;i<n;i++)cin>>arr[i];
    // constructSt(st,arr,0,0,n-1);
    // for(int i=0;i<4*n;i++)cout<<st[i]<<" ";
    // cout<<"\n";
    for(int i=0;i<q;i++){
        int t;
        cin>>t;
        if(t==1){
            int a,b,u;
            cin>>a>>b>>u;
            a--;b--;
            updateSt(st,0,0,n-1,a,b,u);
        }
        else{
            int k;
            cin>>k;
            k--;
            // cout<<sumSt(st,arr,0,0,n-1,k,k)<<endl;
            cout<<arr[k]+sumSt(st,arr,0,0,n-1,k,k)<<"\n";
            // for(int i=0;i<4*n;i++)cout<<st[i]<<" ";
            // cout<<"\n";
        }
        
    }
}

int32_t main()
{   
    solve();
   
   return 0;
}