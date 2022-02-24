/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int position(int arr[],int x,int k,int n){
    int i=0;
    while (i<n){
        if(arr[i]==x){
            return i;
        }
        i=i+max(1,abs(arr[i]-x)/k);
    }
    return -1;
}


int main(){
    int arr[]={20,40,50,70,70,60};
    int k=20;
    int x=60;
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<position(arr,x,k,n)<<endl;
    
   return 0;
}
