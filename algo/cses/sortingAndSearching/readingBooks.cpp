#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define vi vector<int>
#define ip pair<int,int>
#define pb push_back
#define ll long long

using namespace std;

void solve(){
    int n;
    cin>>n;
    int books[n];
    int mx=0;
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>books[i];
        mx=max(mx,books[i]);
        sum+=books[i];
    }
    if(mx<sum-mx){
        cout<<sum<<"\n";
    }
    else{
        cout<<2*mx<<"\n";
    }
}

int32_t main()
{
    solve();
   return 0;
}