/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int x,n;
    cin>>x>>n;
    set<int>lights;
    multiset<int>lengths;
    lights.insert(0);
    lights.insert(x);
    lengths.insert(x);
    for(int i=0;i<n;i++){
        int added;
        cin>>added;
        lights.insert(added);
        auto itr=lights.find(added);
        int prevVal = *prev(itr);
        int nextVal = *next(itr);
        lengths.erase(lengths.find(nextVal-prevVal));
        lengths.insert(nextVal-added);
        lengths.insert(added-prevVal);
        cout<<*lengths.rbegin()<<" ";
        
    }
	cout<<endl;
}

int main()
{
    solve();
    return 0;
}
