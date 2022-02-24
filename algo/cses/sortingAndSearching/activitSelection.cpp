/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct S{
    int st;
    int en;
};

bool cmp(const S &a,const S &b){
    return a.en<b.en;
}



void solve(){
    int n;
    cin>>n;
    std::vector<S>vec;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        vec.push_back({a,b});
    }
    sort(vec.begin(),vec.end(),cmp);
    int ans=1;
    int i=0,j=1;
    while(j<n){
        if(vec[j].st>=vec[i].en){
            ans++;
            i=j;
            j++;
        }
        else{
            j++;
        }
    }
    cout<<ans<<endl;
}

int main()
{
    solve();
    return 0;
}
