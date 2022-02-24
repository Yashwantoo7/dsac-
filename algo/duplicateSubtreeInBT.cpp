/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
string preorder(Node* root,unordered_map<string,int> &mp){
    string s;
    if(!root){
        s+="$";
        return s;
    }
    s+=root->data;
    s+=preorder(root->left,mp);
    s+=preorder(root->right,mp);
    mp[s]++;
    return s;
}

bool dupSub(Node *root)
{
     //your code here
     unordered_map <string,int>mp;
     preorder(root,mp);
     for(auto i:mp)
     if(i.second==2 && i.first.length()>3)
     return true;
     return false;
}