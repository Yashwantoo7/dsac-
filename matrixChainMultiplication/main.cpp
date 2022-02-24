// C++ program using memoization
#include <bits/stdc++.h>
using namespace std;
int dp[100][100];

// Function for matrix chain multiplication
int matrixChainMemoised(int* p, int i, int j)
{
    if (i == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    dp[i][j] = INT_MAX;
    for (int k = i; k < j; k++)
    {
        dp[i][j] = min(
            dp[i][j], matrixChainMemoised(p, i, k)
                     + matrixChainMemoised(p, k + 1, j)
                       + p[i - 1] * p[k] * p[j]);
    }
    return dp[i][j];
}
int MatrixChainOrder(int* p, int n)
{
    int i = 1, j = n - 1;
    return matrixChainMemoised(p, i, j);
}

int matrixChainBottomUP(int m[],int n){

    int dp[101][101];
    for(int i=1;i<n;i++)
        dp[i][i]=0;

    for(int L=2;L<n;L++){
        for(int i=1;i<=n-L;i++){
            int j=i+L-1;
            dp[i][j]=INT_MAX;
            for(int k=i;k<j;k++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+m[i-1]*m[k]*m[j]);
            }
        }
    }
    return dp[1][n-1];

}

// Driver Code
int main()
{
    int arr[] = { 1, 2, 3, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    memset(dp, -1, sizeof dp);

    cout << "Minimum number of multiplications is "
         << MatrixChainOrder(arr, n);

    cout<<"Minimum number of Multiplications using bottom up is "<<
    matrixChainBottomUP(arr,n);
}
