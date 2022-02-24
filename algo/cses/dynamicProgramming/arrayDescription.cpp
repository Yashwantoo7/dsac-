// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;

// int dp[100005][105];
// int mod=(int)1e9 +7;

// int valid(int arr[],int n){
//     for(int i=0;i<n-1;i++){
//         if(abs(arr[i+1]-arr[i])>1)return 0;
//     }
//     return 1;
// }

// int validArr(int i,int arr[],int n,int count,int m){
//     if(count==0){
//         return valid(arr,n);
//     }
    
//     if(arr[i]==0){
//         if(arr[i-1]==1){
//             arr[i]=1;
//             int a=validArr(i+1,arr,n,count-1,m);
//             arr[i]=2;
//             int b=validArr(i+1,arr,n,count-1,m);
//             arr[i]=0;
//             return (a+b)%mod;
//         }
//         else{
//             arr[i]=arr[i-1];
//             int a=validArr(i+1,arr,n,count-1,m);
//             int b=0;
//             if(arr[i-1]!=m){
//                 arr[i]=arr[i-1]+1;
//                 b=validArr(i+1,arr,n,count-1,m);
//             }
//             arr[i]=arr[i-1]-1;
//             int c=validArr(i+1,arr,n,count-1,m);
//             arr[i]=0;
//             return (a+b+c)%mod;
//         }
        
//     }
//     else{
//         int a=validArr(i+1,arr,n,count,m);
//         a%mod;
//         return a%mod;
//     }
// }

// void solve(){
//     memset(dp,-1,sizeof(dp));
//     int n,m;
//     cin>>n>>m;
//     int arr[n];
//     int count=0;
//     for(int i=0;i<n;i++){cin>>arr[i],arr[i]==0?count+=1:count+=0;}
//     int ans=0;
//     if(count==0){
//         cout<<valid(arr,n)<<endl;
//     }
//     else{
//         if(arr[0]!=0)
//         cout<<validArr(1,arr,n,count,m)<<endl;
//         else{
//             int ans=0;
//             for(int i=1;i<=m;i++){
//                 arr[0]=i;
//                 ans+=((validArr(1,arr,n,count-1,m)))%mod;
//             }
//             cout<<ans<<endl;
//         }
//     }
    
// }
// int main()
// {
  
//   solve();
//   return 0;
// }



 
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
 
int solve(int n, int m, vector<int>& v)
{
    int dp[n+2][m+2];
    memset(dp, 0, sizeof dp);
 
    for(int i = 1; i <= n; i++)
    {
        for(int x = 1; x <= m; x++)
        {
            if(i == 1)
            {
                if(v[i] == 0 || v[i] == x)
                    dp[i][x] = 1;
                else dp[i][x] = 0;
            }
            else
            {
                if(v[i] == 0 || v[i] == x){
                    dp[i][x] = ((dp[i-1][x-1] + dp[i-1][x])%mod + dp[i-1][x+1])%mod;
                }
                else dp[i][x] = 0;
            }
        }
    }
 
    int ans = 0;
    for(int x = 1; x <= m; x++)
        ans = (ans + dp[n][x]) % mod;
    return ans;
}
 
int main() {
   fast_io;
   ll t,n,m,x,i,j,k,q;
   //cin >> t;
   t = 1;
   while(t--)
   {
        int n,m;
        cin >> n >> m;
        vector<int> v(n+1);
        fr(1,n+1)
            cin >> v[i];
        cout << solve(n,m,v);
   }
   return 0;
}