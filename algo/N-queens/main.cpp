#include <iostream>
#include <vector>
using namespace std;


bool isSafe(int x,int y,vector<vector<int>>&board,int n){
    for(int i=0;i<x;i++){
        if (board[i][y]!=0){
            return false;
        }
    }
    int i=x,j=y;
    while (i>0 &&j>0){
        if(board[i-1][j-1]!=0)
        return false;
        i-=1;
        j-=1;
    }
    i=x;
    j=y;
    while (i>0 &&j<n-1){
        if(board[i-1][j+1]!=0)
        return false;
        i-=1;
        j+=1;
    }
    return true;

}

void pos(int i,vector<vector<int>>&board,int n){
    if(i==n){
//        cout<<"[";
//        for (int i=0;i<board.size()-1;i++){
//            for(int j=0;j<board.size();j++){
//                if(board[i][j])
//                cout<<board[i][j]<<" ";
//            }
//
//        }
//        for(int j=0;j<board.size();j++){
//        if(board[i-1][j])
//        cout<<board[n-1][j]<<"]";
//        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board.size();j++){
                cout<<board[i][j]<<" ";}
                cout<<endl;
            }
            cout<<endl;
    }
    for(int j=0;j<n;j++){
        if (isSafe(i,j,board,n)){
            board[i][j]=j+1;
            pos(i+1,board,n);
            board[i][j]=0;
            }
    }
    return ;
}

int main() {

	int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> board(n,vector<int>(n,0));
        pos(0,board,n);
    }

	return 0;
}
