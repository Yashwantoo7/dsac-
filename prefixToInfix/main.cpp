#include <iostream>
#include <stack>
#include <string>

using namespace std;

string prefixToInfix(string prefix){
stack <string> s;
string op1{},op2{},exp{};

for(int i=prefix.length()-1;i>=0;i--){
    if((prefix[i]>='a'&&prefix[i]<='z')||(prefix[i]>='A'&&prefix[i]<='Z')){
        string x(1,prefix[i]);
        s.push(x);
    }
    else{
        op1=s.top();
        s.pop();
        op2=s.top();
        s.pop();
        exp="("+op1+prefix[i]+op2+")";
        s.push(exp);
    }
    }
    return s.top();
    }

int main()
{
    string prefix{};
    cout<<"Enter prefix expression : ";
    cin>>prefix;
    cout<<endl<<"infix expression is : "<<prefixToInfix(prefix)<<endl;
    return 0;
}
