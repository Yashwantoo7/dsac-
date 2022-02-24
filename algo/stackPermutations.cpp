/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <stack>
#include <queue> 

using namespace std;

bool permu(stack <int>stk,queue<int>q1 ,queue<int>q2,queue<int>out){
    while(!q1.empty()){
        if(q1.front()==out.front()){
            q1.pop();
            out.pop();
            while(!stk.empty()){
                if(stk.top()!=out.front()) break;
                stk.pop();
                out.pop();
            }
        }
        else{
            stk.push(q1.front());
            q1.pop();
        }
    }
    if(q1.size()==out.size()) return true;
    return false;
}


int main()
{
    stack<int>stk;
    queue<int> q1;
    queue<int> q2;
    queue<int>out;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    
    out.push(3);
    out.push(1);
    out.push(2);
    
    cout<<permu(stk,q1,q2,out)<<endl;
    
    return 0;
}
