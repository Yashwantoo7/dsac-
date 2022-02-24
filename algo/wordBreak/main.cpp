#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

string substring(int st,int en,string sen){
    string s="";
    for(int i=st;i<en;i++){
        s+=sen[i];
    }
    return s;
}

vector<string> wordBreak(string sen,vector<string> vec,int n,string s,int st,unordered_set<string> uns){
    for(int i=st;i<=n;i++){
        string temp;
        temp=substring(st,i,sen);
        if(uns.find(temp)!=uns.end()){
            if(i==n){
                s+=temp;
//                cout<<s<<endl;
                vec.push_back(s);
                return vec;
            }
            vec=wordBreak(sen,vec,n,s+temp+" ",i,uns);
        }
    }
    return vec;
}

int main()
{
    string sen="snakesandladder";

    string arr[]={"snake", "snakes", "and", "sand", "ladder"};

    unordered_set<string> uns;
    for(string i:arr){
        uns.insert(i);
    }
//    unordered_set<string> ::iterator itr;
//    for(itr=uns.begin();itr!=uns.end();itr++){
//        cout<<*itr<<endl;
//    }
    string s="";
    int n=sen.length();
    int st=0;
    vector<string> vec;
    vec=wordBreak(sen,vec,n,s,st,uns);
    for(string i:vec){
        cout<<i<<endl;
    }
    return 0;
}
