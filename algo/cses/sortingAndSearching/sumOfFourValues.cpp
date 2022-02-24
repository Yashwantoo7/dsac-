// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         vector<vector<int>> res;
//         sort(nums.begin(),nums.end());
//         int n=nums.size();
        
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 int x=target-(nums[i]+nums[j]);
//                 int l=j+1,r=n-1;
//                 while(l<r){
//                     int sum=nums[l]+nums[r];
//                     if(x>sum)l++;
//                     else if(x<sum)r--;
//                     else{
//                         vector<int> quad(4,0);
//                         quad[0]=nums[i];
//                         quad[1]=nums[j];
//                         quad[2]=nums[l];
//                         quad[3]=nums[r];
//                         res.push_back(quad);
//                         while(l<r && nums[l]==quad[2])l++;
//                         while(r>l && nums[r]==quad[3])r--;
//                     }
//                 }
//                 while(j+1<n && nums[j+1]==nums[j])j++;
//             }
//             while(i+1<n && nums[i+1]==nums[i])i++;
//         }
//         return res;
//     }
// };

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
    int n,sum;
    cin>>n>>sum;
    if(n<4){cout<<"IMPOSSIBLE";return;}
    
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    
    map<int,ip>mp;
    mp[arr[0]+arr[1]]={1,2};
    for(int i=2;i<n;i++){
        for(int j=i+1;j<n;j++){
            int target=sum-(arr[i]+arr[j]);
            if(mp.find(target)!=mp.end()){
                cout<<mp[target].first<<" "<<mp[target].second<<" "<<i+1<<" "<<j+1;
                return;
            }
        }
        for(int k=0;k<i;k++){
            mp[arr[k]+arr[i]]={k+1,i+1};
        }
    }
    cout<<"IMPOSSIBLE";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
   return 0;
}