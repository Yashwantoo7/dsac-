#include <iostream>
#include <stack>
#include <string>

using namespace std;

string postfixToInfix(string postfix){
    stack <string> s;
    string op1{};
    string op2{};
    string exp{};

    for (int i=0 ;i<postfix.length();i++){
        if((postfix[i]>='a'&&postfix[i]<='z')||(postfix[i]>='A'&&postfix[i]<='Z')){
            string x(1,postfix[i]);
            s.push(x);
        }
        else{
            op1=s.top();
            s.pop();
            op2=s.top();
            s.pop();
            exp='('+op2+postfix[i]+op1+')';
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
    cout<<endl<<"infix expression is : "<<postfixToInfix(postfix)<<endl;
    return 0;
}
