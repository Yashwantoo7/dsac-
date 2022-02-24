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
    int n,m,k;
    cin>>n>>m>>k;
    int app[n],apr[m];
    for(int i=0;i<n;i++)cin>>app[i];
    for(int j=0;j<m;j++)cin>>apr[j];
    sort(app,app+n,cmp);
    sort(apr,apr+m,cmp);

    int i=0,j=0;
    int ans=0;
    while(i<n && j<m){
        if(abs(app[i]-apr[j])<=k){
            i++;j++;
            ans++;
        }
        else if(app[i]>apr[j]){
            j++;
        }
        else{
            i++;
        }
    }
    cout<<ans<<endl;
}

int main()
{
   solve();
    return 0;
}
