#include <iostream>
using namespace std;
#include <stack>
#include <string>

int main() {
	//code
	int t;
	cin>>t;
	cin.get();
	while(t--){
	    string exp;
	    getline(cin,exp);
	   // cout<<exp;
	    stack <int> stk;
	    int n=exp.length();
	    for(int i=0;i<n;i++){
	        if(exp[i]=='*'||exp[i]=='+'||exp[i]=='-'||exp[i]=='/'){
	           int val;
	            int op1=stk.top();
	            stk.pop();
	            int op2=stk.top();
	            stk.pop();
	            if(exp[i]=='*')
	            val=op2*op1;
	            else if(exp[i]=='/')
	            val=op2/op1;
	            else if(exp[i]=='+')
	            val=op2+op1;
	            else if(exp[i]=='-')
	            val=op2-op1;
	            stk.push(val);
	        }
	        else{
	            stk.push(exp[i]-'0');
	        }
	}
	cout<<stk.top()<<endl;
	}

	return 0;
}
