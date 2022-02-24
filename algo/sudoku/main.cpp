#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>> board,int i,int j,int n,int val){
    //column
    for(int r=0;r<n;r++){
        if(board[r][j]==val&&r!=i)
            return false;
    }
    //row
    for(int c=0;c<n;c++){
        if(board[i][c]==val&&c!=j)
            return false;
    }
    //box
    int r,c;
    r=i/3;
    c=j/3;
    for(int row=r*3;row<r*3+3;row++){
        for(int col=c*3;col<c*3+3;col++){
            if(board[row][col]==val&&row!=i&&col!=j)
                return false;
        }
    }
    return true;
}

vector<int> emptyPos(vector<vector<int>> board,int n){
    vector<int>pos={};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (board[i][j]==0){
                pos.push_back(i);
                pos.push_back(j);
                return pos;
            }
        }
    }
    return pos;
}

bool solve(vector<vector<int>> board,int n){
    vector<int>pos=emptyPos(board,n);
    if(pos.size()==0){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    for(int i=1;i<10;i++){
        if(isSafe(board,pos[0],pos[1],n,i)){
//                cout<<pos[0]<<" "<<pos[1]<<" "<<i<<endl;
            board[pos[0]][pos[1]]=i;
            if(solve(board,n))
                return true;
            board[pos[0]][pos[1]]=0;
        }
    }
    return false;
    }


int main()
{
    vector<vector<int>> board = {
    {7,8,0,4,0,0,1,2,0},
    {6,0,0,0,7,5,0,0,9},
    {0,0,0,6,0,1,0,7,8},
    {0,0,7,0,4,0,2,6,0},
    {0,0,1,0,5,0,9,3,0},
    {9,0,4,0,6,0,0,0,5},
    {0,7,0,3,0,0,0,1,2},
    {1,2,0,0,0,7,4,0,0},
    {0,4,9,2,0,6,0,0,7}
    };
    bool solved;
    solved=solve(board,9);
    return 0;
}
