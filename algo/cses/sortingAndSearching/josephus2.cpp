#include <iostream>
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
  
  
#define ll long long
 
using namespace std;
 
void solve(){
    int n,k;
    cin>>n>>k;
    ordered_set oset;
    for(int i=1;i<=n;i++){
        oset.insert(i);
    }
    int startpos = 0;
    while(!oset.empty()){
        startpos %= oset.size();
        int posTormv = (startpos+k)%oset.size();
        startpos = posTormv;
        auto t = oset.find_by_order(posTormv);
        cout<<*t<<" ";
        oset.erase(t);
    }
}
int main()
{
    solve();
   return 0;
}