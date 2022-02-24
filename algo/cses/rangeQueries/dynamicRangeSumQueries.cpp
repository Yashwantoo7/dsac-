#include <iostream>
#include <bits/stdc++.h>
#define int long long

using namespace std;



int constructSt(int st[],int arr[],int si,int l,int r){
    if(l==r){
        st[si]=arr[l];
        return arr[l];
    }
    int mid = (l+r)/2;
    st[si] = min(constructSt(st,arr,2*si+1,l,mid),constructSt(st,arr,2*si+2,mid+1,r));
    return st[si];
}

void updateSt(int st[],int si,int sl,int sr,int pos,int val){
    // if(sl>pos || sr<pos)return;
    // if(sl==sr)st[si]=val;
    
    // if(sl!=sr){
    //     int mid=(sl+sr)/2;
    //     updateSt(st,2*si+1,sl,mid,pos,val);
    //     updateSt(st,2*si+2,mid+1,sr,pos,val);
    // }
    // st[si]=min(st[si],val);
    if(sl==sr){
        st[si]=val;
    }
    else{
        int mid=(sl+sr)/2;
        if(pos>=sl && pos<=mid){
            updateSt(st,2*si+1,sl,mid,pos,val);
        }
        else{
            updateSt(st,2*si+2,mid+1,sr,pos,val);
        }
        st[si] = min(st[2*si+1],st[2*si+2]);
    }
    return;
}

int minSt(int st[],int arr[],int si,int sl,int sr,int l,int r){
    if(l<=sl && r>=sr){
        return st[si];
    }
    if(l>sr || sl>r){
        return (int)1e10;
    }
    int mid = (sl+sr)/2;
    return min(minSt(st,arr,2*si+1,sl,mid,l,r),minSt(st,arr,2*si+2,mid+1,sr,l,r));
}

void solve(){
    int n,q;
    cin>>n>>q;
    int arr[n];
    int st[4*(n)]={0};
    for(int i=0;i<n;i++)cin>>arr[i];
    constructSt(st,arr,0,0,n-1);
    // for(int i=0;i<4*n;i++)cout<<st[i]<<" ";
    // cout<<"\n";
    for(int i=0;i<q;i++){
        int t,a,b;
        cin>>t>>a>>b;
        if(t==1){
            a--;
            arr[a]=b;
            updateSt(st,0,0,n-1,a,b);
        }
        else{
            a--;b--;
        cout<<minSt(st,arr,0,0,n-1,a,b)<<"\n";}
    }
}

int32_t main()
{   
    solve();
   
   return 0;
}