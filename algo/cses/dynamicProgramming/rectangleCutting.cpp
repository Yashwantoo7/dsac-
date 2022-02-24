#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int dp[505][505];

void solve(){
    int n,m;
    cin>>n>>m;
    if(n>m)swap(n,m);
    
    for(int h=1;h<=n;h++){
        for(int w=1;w<=m;w++){
            if(h==w){
                dp[h][w]=0;
            }
            else{
                int ans = h*w +1;
                for(int vr=1;vr<w;vr++){
                    ans=min(ans,1+dp[h][vr]+dp[h][w-vr]);
                }
                for(int hr=1;hr<h;hr++){
                    ans=min(ans,1+dp[h-hr][w]+dp[hr][w]);
                }
                dp[h][w]=ans;
            }
        }
    }
    cout<<dp[n][m]<<endl;
}

int main()
{
    solve();
    return 0;
}
