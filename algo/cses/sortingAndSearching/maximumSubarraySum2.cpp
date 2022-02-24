#include <iostream>
#include <bits/stdc++.h>
#define int long long

using namespace std;


struct movie{
    int st;
    int en;
};

bool cmp(const movie & m1,const movie &m2){
    if(m1.en==m2.en)return m1.st<m2.st;
    return m1.en<m2.en;
}


void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    int arr[n+1];
    for(int i=1;i<=n;i++)cin>>arr[i];
    
    int preSum[n+1];
    preSum[0]=0;
    for(int i=1;i<=n;i++){
        preSum[i]=preSum[i-1]+arr[i];
    }
    
    multiset<int> mset;
    for(int i=a;i<=b;i++){
        mset.insert(preSum[i]);
    }
    int ans=*mset.rbegin();
    for(int i=1;i+a-1<=n;i++){
        ans=max(ans,*mset.rbegin()-preSum[i-1]);
        auto it = mset.find(preSum[i+a-1]);
        // cout<<*it<<endl;
        mset.erase(it);
        if(b+i<=n)
        mset.insert(preSum[b+i]);
    }
    cout<<ans;
}

int32_t main()
{   
    solve();
   return 0;
}