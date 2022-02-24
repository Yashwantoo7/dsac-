/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Partition{
    int left,right;
};

Partition partition(int arr[],int begin,int end){
    int l=begin,g=end,curr=begin;
    int comp=arr[begin];
    while(curr<=g){
        if(arr[curr]<comp){
            swap(arr[curr],arr[l]);
            curr++,l++;
        }
        else if(arr[curr]>comp){
            swap(arr[curr],arr[g]);
            g--;
        }
        else{
            curr++;
        }
    }
    Partition p={l,g};
    return p;
    
}

void quickSort(int arr[],int begin,int end,int n){
    if(begin>=end) return ;
    Partition middlePart=partition(arr,begin,end);
    quickSort(arr,begin,middlePart.left-1,n);
    quickSort(arr,middlePart.right+1,end,n);
}

int main()
{
    // cout<<"Hello World";
    int arr[]={3,5,4,3,1,2,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<n<<endl;
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";}
    quickSort(arr,0,n-1,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";}
    
    cout<<endl;
    return 0;
}
