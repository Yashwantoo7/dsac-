#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define vi vector<int>
#define ip pair<int,int>
#define pb push_back
#define ll long long

using namespace std;

bool cmp(const ip &p1,const ip &p2){
    return p1.first<p2.first;
}

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    stack<int>stk;
    stk.push(0);
    for(int i=0;i<n;i++){
        if(stk.top()==0){
            cout<<0<<" ";
            stk.push(i+1);
        }
        else{
            while(stk.top()!=0 && arr[stk.top()-1]>=arr[i]){
                stk.pop();
            }
            cout<<stk.top()<<" ";
            stk.push(i+1);
        }
    }
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
   return 0;
}