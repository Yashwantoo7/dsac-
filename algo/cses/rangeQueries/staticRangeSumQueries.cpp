#include <iostream>
#include <bits/stdc++.h>
#define int long long

using namespace std;

int minSt(int st[],int arr[],int si,int sl,int sr,int l,int r){
    if(l<=sl && r>=sr){
        return st[si];
    }
    if(l>sr || sl>r){
        return (int)1e10;
    }
    int mid = sl+(sr-sl)/2;
    return min(minSt(st,arr,2*si+1,sl,mid,l,r),minSt(st,arr,2*si+2,mid+1,sr,l,r));
}

int constructSt(int st[],int arr[],int si,int l,int r){
    if(l==r){
        st[si]=arr[l];
        return arr[l];
    }
    int mid = l+(r-l)/2;
    st[si] = min(constructSt(st,arr,2*si+1,l,mid),constructSt(st,arr,2*si+2,mid+1,r));
    return st[si];
}

void solve(){
    int n,q;
    cin>>n>>q;
    int arr[n];
    int st[4*(n)];
    for(int i=0;i<n;i++)cin>>arr[i];
    constructSt(st,arr,0,0,n-1);
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        cout<<minSt(st,arr,0,0,n-1,a,b)<<"\n";
    }
}

int32_t main()
{   
    solve();
   
   return 0;
}