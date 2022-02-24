/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct S{
    int val;
    int ind;
};

bool cmp(const S &a,const S &b){
    return a.val<b.val;
}

// bool cmp(const int &a, const int &b){
//     return a<b;
// }

void solve(){
    int n;
    cin>>n;
    ll sum=0;
    ll arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int x=arr[(n/2)];
    for(int i=0;i<n;i++){
        sum+=abs(arr[i]-x);
    }
    cout<<sum<<endl;
}

int main()
{
    solve();
    return 0;
}
