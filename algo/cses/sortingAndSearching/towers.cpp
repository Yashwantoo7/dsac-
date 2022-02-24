
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
    multiset<int>ms;
    int cube;
    cin>>cube;
    ms.insert(cube);
    for(int i=0;i<n-1;i++){
        cin>>cube;
        auto it=ms.upper_bound(cube);
        if(it==ms.end()){
            ms.insert(cube);
        }
        else{
            ms.erase(it);
            ms.insert(cube);
        }
    }
    cout<<ms.size()<<endl;
}

int main()
{
    solve();
    return 0;
}
