/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int countPS(string str)
{
   //Your code here
   int n=str.length();
   int dp[n][n];
   
   int row=n;
   int col=0;
   int r,c;
   
   while(row>0){
       r=0;
       c=col;
       while(r<row){
           if(r==c) dp[r][c]=1;
           
           else if(abs(r-c)==1){
               if(str[r]==str[c]){
                   dp[r][c]=3;
               }
               else{
                   dp[r][c]=2;
               }
           }
           
           else{
               if(str[r]==str[c]){
                   dp[r][c]=dp[r][c-1]+dp[r+1][c]+1;
               }
               else{
                   dp[r][c]=dp[r][c-1]+dp[r+1][c]-dp[r+1][c-1];
               }
           }
           r+=1;
           c+=1;
       }
       row-=1;
       col+=1;
   }
   return dp[0][c-1];
}

int main()
{   
    string s="AABAACAABAA";
    cout<<countPS(s);
    

    return 0;
}
