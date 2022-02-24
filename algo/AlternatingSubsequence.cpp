/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<vector>

using namespace std;

int AlternatingaMaxLength(vector<int>&nums){
		    // Code here
		    //condition 1
		    int n=nums.size();
		    int ma=1,mi=1;
		    for(int i=1;i<n;i++){
		        if(nums[i]>nums[i-1]) ma=mi+1;
		        else if(nums[i]<nums[i-1]) mi=ma+1;
		    }
		    return max(mi,ma);
    	    
		}

int lgSub(std::vector<int> &vec){
    int n=vec.size();
    if(n==1)return 1;
    int dp[n][2];
    for(int i=0;i<n;i++){
        dp[i][0]=dp[i][1]=1;
    }
    int mx=0;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(vec[i]>vec[j] and dp[i][0]<dp[i][1]+1)dp[i][0]=dp[i][1]+1;
            else if(vec[i]<vec[j] and dp[i][1]<dp[i][0]+1)dp[i][1]=dp[i][0]+1;
        }
        mx=max(mx,max(dp[i][0],dp[i][1]));
    }
    return mx;
}

int main()
{
    vector<int> vec={1,17,5,10,13,15,10,5,16,8};
    cout<<lgSub(vec)<<endl;
    cout<<AlternatingaMaxLength(vec)<<endl;
    return 0;
}
