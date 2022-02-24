#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define vi vector<int>
#define ip pair<int,int>
#define pb push_back
#define ll long long

using namespace std;

struct task{
  int du;
  int de;
};

bool cmp(const task & t1,const task &t2){
    return t1.du<t2.du;
}

void solve(){
    int n;
    cin>>n;
    task arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].du>>arr[i].de;
    }
    sort(arr,arr+n,cmp);
    int t=0;
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=arr[i].de - (arr[i].du+t);
        t+=arr[i].du;
    }cout<<ans<<"\n";
}

int32_t main()
{
    solve();
   return 0;
}