/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;



void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ll ans=1;
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        if(ans<arr[i]){
            break;
        }
        else{
            ans+=arr[i];
        }
    }
    cout<<ans<<endl;
}
int main()
{
   solve();
    return 0;
}
