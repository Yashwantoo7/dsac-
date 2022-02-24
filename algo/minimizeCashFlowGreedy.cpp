/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

# define N 5

int getMin(int amount[]){
    int minIdx=0;
    for(int i=1;i<N;i++){
        if (amount[minIdx]>amount[i]) minIdx=i;
    }
    return minIdx;
}


int getMax(int amount[]){
    int maxIdx=0;
    for(int i=1;i<N;i++){
        if (amount[maxIdx]<amount[i]) maxIdx=i;
    }
    return maxIdx;
}

int minOf(int a,int b){
    return a<b?a:b;
}

void helper(int amount[]){
    int maxCredit=getMax(amount);
    int maxDebt=getMin(amount);
    
    if (amount[maxDebt]==0 && amount[maxCredit]==0) return ;
    
    int min=minOf(-amount[maxDebt],amount[maxCredit]);
    amount[maxCredit]-=min;
    amount[maxDebt]+=min;
    
    cout<<"person "<<maxDebt<<" pays "<<min<<" to person "<<maxCredit<<endl;
    
    helper(amount);
}

void minTransaction(int graph[][N]){
    int amount[N]={0};
    for(int p=0;p<N;p++){
       for(int i=0;i<N;i++){
           amount[p]+=(graph[i][p]-graph[p][i]);
       }
    }
    for(int i:amount){
        cout<<i<<" ";
    }
    
    helper(amount);
}

int main()
{    int graph[N][N]={{0,10,0,0,0},
                     {0,0,20,0,40},
                     {0,0,0,30,0},
                     {0,0,0,0,0},
                     {0,0,0,0,0}};
     minTransaction(graph);
    return 0;
}
