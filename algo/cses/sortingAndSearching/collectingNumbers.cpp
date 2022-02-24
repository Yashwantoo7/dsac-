
#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct S{
    int val;
    int ind;
};

bool cmp(const S &a,const S &b){
    return a.val<b.val;
}

// bool cmp(const int &a, const int &b){
//     return a<b;
// }

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    set<int>st;
    queue<int>q;
    int ans=0;
    for(int i=0;i<n;i++){
        if(st.find(arr[i])!=st.end()){
            if(q.size()>ans)ans=q.size();
            while(q.front()!=arr[i]){
                st.erase(q.front());
                q.pop();
            }
            st.erase(q.front());
            q.pop();
        }
        st.insert(arr[i]);
        q.push(arr[i]);
    }
    if(q.size()>ans)ans=q.size();
    cout<<ans<<endl;
}

int main()
{
    solve();
    return 0;
}
