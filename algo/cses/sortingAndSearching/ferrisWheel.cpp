/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool cmp(const int &a,const int &b){
    return a<b;
}

void solve(){
    int n,x;
    cin>>n>>x;
    int weights[n];
    for(int i=0;i<n;i++)cin>>weights[i];
    sort(weights,weights+n,cmp);
    int ans=0;
    int curr=0;
    int i=0,j=n-1;
    while(i<j){
        if(weights[i]+weights[j]<=x){
            ans++;
            i++;
            j--;
        }
        else{
            ans++;
            j--;
        }
    }
    if(i==j)ans++;
    cout<<ans<<endl;
}

int main()
{
   solve();
    return 0;
}
