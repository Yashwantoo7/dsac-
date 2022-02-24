/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minCost(int keys[],int freq[],int n){
    int dp[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j]=0;
        }
    }
    int R,C;
    R=n-1;C=0;
    while(R>=0){
        int r,c;
        r=0;c=C;
        while(r<=R){
            if(r==c) dp[r][c]=freq[r];
            else if(c-r==1)dp[r][c]=min(1*freq[r]+2*freq[c],1*freq[c]+2*freq[r]);
            else{
                int x=INT_MAX;
                for(int k=r;k<=c;k++){
                    if(k==r)x=min(x,dp[r+1][c]);
                    else if(k==c)x=min(x,dp[r][c-1]);
                    else{
                        x=min(x,dp[r+k+1][c]+dp[r][k-1]);
                    }
                }
                dp[r][c]=x;
                for(int i=r;i<=c;i++)
                dp[r][c]+=freq[i];
            }
            r++;
            c++;
        }
        R--;
        C++;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[0][n-1];
}

int main()
{   
    int n=4;
    int keys[]={10,20,30,40};
    int freq[]={3,1,2,1};
    cout<<minCost(keys,freq,n)<<endl;
    return 0;
}
