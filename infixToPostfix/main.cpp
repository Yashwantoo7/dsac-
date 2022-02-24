#include <iostream>
#include <stack>
#include <string>

using namespace std;
bool isOperator(char c){
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^'){
        return true;
    }
    else{
        return false;
    }
}

int precedence(char c){
    if(c=='^')
        return 3;
    else if(c=='*'||c=='/')
        return 2;
    else if(c=='+'||c=='-')
        return 1;
    else
        return -1;
}
string infixToPostfix(stack <char> s, string infix){
    string postfix;
    for(int i=0;i<infix.length();i++){
        if((infix[i]>='a'&&infix[i]<='z')||(infix[i]>='A'&&infix[i]<='Z')){
            postfix+=infix[i];
        }
        else if(infix[i]=='('){
                    s.push(infix[i]);
                }
        else if(infix[i]==')'){
            char temp;
            while((s.top()!='(')&&(!s.empty()))
            {
                temp=s.top();
                postfix+=temp;
                s.pop();
            }
            if(s.top()=='('&&(!s.empty())){
                s.pop();
               }
        }
        else if(isOperator(infix[i])){
            if(s.empty()){
                s.push(infix[i]);
            }
            else{
                if(precedence(infix[i])>precedence(s.top())){
                    s.push(infix[i]);
                }
                else if((precedence(infix[i])==precedence(s.top())&&(infix[i]=='^'))){
                    s.push(infix[i]);
                }
                else{
                        char temp;
                    while((!s.empty())&&(precedence(infix[i])<=precedence(s.top()))){
                        temp=s.top();
                        postfix+=temp;
                        s.pop();
                    }
                    s.push(infix[i]);
                }
            }
        }
        }
        while(!s.empty()){
            postfix+=s.top();
            s.pop();
        }
        return postfix;
    }

int main()
{
    string infix,postfixExp;
    cout<<"enter a infix expression :"<<endl;
    cin>>infix;
    stack <char> s;
    cout<<"infix expression: "<<infix<<endl;
    postfixExp=infixToPostfix(s,infix);
    cout<<endl<<"postfixExp expression: "<<postfixExp;
    return 0;
}
