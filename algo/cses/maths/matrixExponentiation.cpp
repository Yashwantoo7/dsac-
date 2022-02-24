#include <iostream>
#include <bits/stdc++.h>
#define int long long

using namespace std;

int m = (int)1e9 + 7;

vector<vector<int>>multiply(vector<vector<int>>&a,vector<vector<int>>&b){
    int n = a.size();
    vector<vector<int>>ans(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                ans[i][j] = (ans[i][j]%m+(a[i][k]*b[k][j])%m)%m;
            }
        }
    }
    return ans;
}

vector<vector<int>> matrixExpo(vector<vector<int>>&a,int n){
    if(n==0){
        return {{(int)1,(int)0},{(int)0,(int)1}};
    }
    vector<vector<int>>temp = matrixExpo(a,n/2);
    vector<vector<int>>ans = multiply(temp,temp);
    if(n&1){
        ans = multiply(ans,a);
    }
    return ans;
}

int32_t main()
{
   int n;
   cin>>n;
   vector<vector<int>>a = {{(int)1,(int)1},{(int)1,(int)0}};
   a=matrixExpo(a,n);
 
   cout<<a[0][1]<<endl;
   return 0;
}