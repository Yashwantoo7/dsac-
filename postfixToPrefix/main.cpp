#include <iostream>
#include <string>
#include <stack>

using namespace std;

string postfixToPrefix(string postfix){
    stack <string> s;
    string op1{},op2{},exp{};
    for(int i=0;i<postfix.length();i++){
        if((postfix[i]>='a'&&postfix[i]<='z')||(postfix[i]>='A'&&postfix[i]<='Z'))
        {string x(1,postfix[i]);
        s.push(x);
        }
        else{
            op1=s.top();
            s.pop();
            op2=s.top();
            s.pop();
            exp=postfix[i]+op2+op1;
            s.push(exp);
        }
    }
    return s.top();
    }

int main()
{
    string postfix{};
    cout<<"Enter postfix expression : ";
    cin>>postfix;
    cout<<endl<<"prefix expression is : "<<postfixToPrefix(postfix)<<endl;
    return 0;
}
