#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <set>

using namespace std;

bool isBalanced(string exp){
    stack<char> stk;
    for(int i=0;i<exp.length();i++){
        if(stk.empty()&&exp[i]==')')
            return false;
        else if(exp[i]==')'){
            stk.pop();
        }
        else if(exp[i]=='(')
            stk.push('(');
    }
    if (stk.empty())
        return true;
    return false;
}

int getMin(string exp,int n){
    stack<char> stk;
    for(int i=0;i<n;i++){
        if(exp[i]=='(')
            stk.push('(');
        else if(exp[i]==')'&&stk.empty())
            stk.push(')');
        else if(exp[i]==')'&&stk.top()=='(')
            stk.pop();
        else if(exp[i]==')'&&stk.top()==')')
            stk.push(')');
    }
    return stk.size();
}

vector <string> rmvInvalid(string exp,int st,int n,vector<string>vec,int minRemovel){
    if(isBalanced(exp)&& minRemovel>=0){
        vec.push_back(exp);
        return vec;
    }
    if(minRemovel<=0){
        return vec;
    }
    if(st>=n)
        return vec;
    vector<string>vec1,vec2;
    vec1=rmvInvalid(exp.substr(0,st)+exp.substr(st+1,n),st,n-1,vec,minRemovel-1);
    vec2=rmvInvalid(exp,st+1,n,vec,minRemovel);
    vec1.insert(vec1.end(),vec2.begin(),vec2.end());
    vec.insert(vec.end(),vec1.begin(),vec1.end());
    return vec;
}

int main()
{
    string exp="()a())()";
    cout<<boolalpha;
    vector<string>vec;
    int minRemovel;
    int n=exp.length();
    set<string> s;
    minRemovel=getMin(exp,n);
    vec=rmvInvalid(exp,0,n,vec,minRemovel);
    for(string i:vec){
        s.insert(i);
    }
    for(string i:s)
        cout<<i<<endl;
    return 0;
}
