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
    int n,m;
    cin>>n>>m;
    multiset<int>ms;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        ms.insert(a);
    }
    for(int i=0;i<m;i++){
        int p;
        cin>>p;
        auto it=ms.lower_bound(p+1);
        if(it==ms.begin()){
            cout<<-1<<endl;
        }
        else{
            --it;
            cout<<*it<<endl;
            ms.erase(it);
        }
    }
}

int main()
{
    solve();
    return 0;
}
