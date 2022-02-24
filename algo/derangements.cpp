/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int derangementsRecu(int n){
    if(n==1 || n==2) return n-1;
    return (n-1)*(derangementsRecu(n-1)+derangementsRecu(n-2));
}

int derangements(int n){
    int prev=1,prevOfPrev=0;
    for(int i=3;i<=n;i++){
        int curr=(i-1)*(prev+prevOfPrev);
        prevOfPrev=prev;
        prev=curr;
    }
    return prev;
}

int main()
{   
    cout<<derangements(5)<<endl;
    cout<<derangementsRecu(5)<<endl;
    return 0;
}
