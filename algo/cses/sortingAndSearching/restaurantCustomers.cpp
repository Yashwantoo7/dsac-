/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct S{
    int ti;
    char ty;
};

bool cmp(const S &a,const S &b){
    return a.ti<b.ti;
}



void solve(){
    int n;
    cin>>n;
    std::vector<S>vec;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        vec.push_back({a,'x'});
        vec.push_back({b,'Y'});
    }
    sort(vec.begin(),vec.end(),cmp);
    int ans=0,count=0;
    for(auto s:vec){
        if(s.ty=='x'){
            count++;
        }
        else{
            ans=max(ans,count);
            count--;
        }
    }
    cout<<ans<<endl;
}

int main()
{
    solve();
    return 0;
}
