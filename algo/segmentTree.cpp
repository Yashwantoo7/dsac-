/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int constructST(int st[],int si,int l,int r,int arr[]){
    if(l==r){
        st[si]=arr[l];
        return arr[l];
    }
    int mid=l+(r-l)/2;
    st[si]=constructST(st,2*si+1,l,mid,arr)+constructST(st,2*si+2,mid+1,r,arr);
    return st[si];
}

int getSum(int st[],int si,int sl,int sr,int l,int r){
    if(l<=sl and r>=sr){ //total overlap
        return st[si];
    }
    if(sl>r or l>sr)return 0;
    int mid=sl+(sr-sl)/2;
    return getSum(st,2*si+1,sl,mid,l,r)+getSum(st,2*si+2,mid+1,sr,l,r);
}

void update(int st[],int si,int sl,int sr,int pos,int diff){
    if(sl>pos or pos>sr)return ;
    st[si]+=diff;
    if(sl!=sr){
        int mid=sl+(sr-sl)/2;
        update(st,2*si+1,sl,mid,pos,diff);
        update(st,2*si+2,mid+1,sr,pos,diff);
    }
    return ;
}

int main()
{   int n=5;
    int arr[n]={1,2,3,4,5};
    int st[4*n]={0};
    constructST(st,0,0,n-1,arr);
    for(int i=0;i<4*n;i++){
        cout<<st[i]<<" ";
    }cout<<endl;
    cout<<getSum(st,0,0,n-1,1,3)<<endl;
    
    arr[2]=10;
    int diff=arr[2]-3;
    update(st,0,0,n-1,2,diff);
    for(int i=0;i<4*n;i++){
        cout<<st[i]<<" ";
    }cout<<endl;
    return 0;
}
