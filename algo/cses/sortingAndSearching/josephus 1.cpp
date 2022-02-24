#include <iostream>
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    int n;
    cin>>n;
    list <int> lst;
    for(int i=1;i<=n;i++)lst.push_back(i);
    
    while(!lst.empty()){
        auto front = lst.front();
        lst.push_back(front);
        lst.pop_front();
        cout<<lst.front()<<" ";
        lst.pop_front();
    }
    
}
int main()
{
    solve();
   return 0;
}