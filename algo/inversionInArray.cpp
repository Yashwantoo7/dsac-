/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void merge(int arr[],int l,int m,int r,long long int &count){
    int n1=m-l+1;
    int n2=r-m;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++){
        L[i]=arr[l+i];
    }
    for(int j=0;j<n2;j++){
        R[j]=arr[m+j+1];
    }
    int i=0,j=0,k=l;
    
    while(i<n1 and j<n2){
        if(L[i]>R[j]){
            count+=n1-i;
            j+=1;
        }
        else{
            i++;
        }
    }
    
    i=0,j=0,k=l;
    
    while(i<n1 and j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i+=1;
        }
        else{
            arr[k]=R[j];
            j+=1;
        }
        k+=1;
    }
    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }
    
}

void mergeSort(int arr[],int l,int r,long long int &count){
    if(l>=r) return ;
    int m=l+(r-l)/2;
    mergeSort(arr,l,m,count);
    mergeSort(arr,m+1,r,count);
    merge(arr,l,m,r,count);
}

int main()
{   int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int l=0,r=n;
    long long int count=0;
    mergeSort(arr,l,r,count);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    cout<<count<<endl;
    return 0;
}
