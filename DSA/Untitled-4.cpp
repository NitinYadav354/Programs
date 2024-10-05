#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int board[9][9], int row, int col, int j){
    //vertical
    for (int i=0; i<9; i++){
        if(board[i][col] == j){
            return false;
        }
    }
    //Horizontal
    for (int i=0; i<9; i++){
        if(board[row][i]==j){
            return false;
        }
    }
    //3x3 grid
    int strROW = (row/3)*3;
    int strCOL = (col/3)*3;
    for (int i=strROW; i<=strROW+2; i++){
        for (int k=strCOL; k<=strCOL+2; k++){
            if (board[i][k]==j){
                return false;
            }
        }
    } 
    return true;
}

void printboard(int board[9][9]){
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            cout<<board[i][j]<<"|";
        }
        cout<<endl<<"-----------------"<<endl;
    }
}

bool sudoku(int board[9][9], int row, int col){
    if (row==9){
        printboard(board);
        return true;
    }
    int nextRow = row;
    int nextcol = col+1;
    if (col+1==9){
        nextRow = row+1;
        nextcol = 0;
    }
    if (board[row][col]!=0){
        return sudoku(board, nextRow, nextcol);
    }
    for (int j=1; j<10; j++){
        if (isSafe(board , row,col, j)){
            board[row][col]=j;
            if (sudoku(board ,nextRow, nextcol)){
                return true;
            }
            board[row][col]=0;
        } 
    }
    return false;
}

int main(){
    int board[9][9]={{0,0,8,0,0,0,0,0,0},
                    {4,9,0,1,5,7,0,0,2},
                    {0,0,3,0,0,4,1,9,0},
                    {1,8,5,0,6,0,0,2,0},
                    {0,0,0,0,2,0,0,6,0},
                    {9,6,0,4,0,5,3,0,0},
                    {0,3,0,0,7,2,0,0,4},
                    {0,4,9,0,3,0,0,5,7},
                    {8,2,7,0,0,9,0,1,3}};
    cout<<"Unsloved Sudoku"<<endl;
    printboard(board);
    cout<<"Solved Sudoku"<<endl;
    if(!sudoku(board, 0, 0)){
        cout<<"No Solution Found"<<endl;
    }
    return 0;
}