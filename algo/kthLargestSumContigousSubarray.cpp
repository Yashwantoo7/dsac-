/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

void heapify(int arr[],int n,int i){
    int l=i*2+1;
    int r=i*2+2;
    int smallest=i;
    if(l<n and arr[l]<arr[i]){
        smallest=l;
    }
    if(r<n and arr[r]<arr[smallest])
        smallest=r;
    if(i!=smallest){
        arr[i]=arr[i]+arr[smallest];
        arr[smallest]=arr[i]-arr[smallest];
        arr[i]=arr[i]-arr[smallest];
        heapify(arr,n,smallest);
    }
}


int main()
{   int n=4;
    int arr[]={10,-10,20,-40};
    int k=3;
    int sums[k]={0};
    int preSums[n]={0};
    preSums[0]=arr[0];
    for(int i=1;i<n;i++){
        preSums[i]=preSums[i-1]+arr[i];
    }
    int s=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
 
            if(s<k){
                if(i==0){
                    sums[s]=preSums[j];
                }
                else{
                    sums[s]=preSums[j]-preSums[i-1];
                }
                s+=1;
            }
            else{
                if(s==k){
                    for(int i=0;i<k;i++){
                        cout<<sums[i]<<" ";
                    }
                    cout<<endl;
                    int x=(k/2);
                    for(int i=x-1;i>-1;i--){
                        heapify(sums,k,i);
                    }
                    for(int i=0;i<k;i++){
                        cout<<sums[i]<<" ";
                    }
                    cout<<endl;
                    
                }
                if(i==0){
                    if(sums[0]<preSums[j]){
                        sums[0]=preSums[j];
                        heapify(sums,k,0);
                    }
                }
                else{
                    if(sums[0]<preSums[j]-preSums[i-1]){
                        sums[0]=preSums[j]-preSums[i-1];
                        heapify(sums,k,0);
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<preSums[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<k;i++){
        cout<<sums[i]<<" ";
    }
    return 0;
}





