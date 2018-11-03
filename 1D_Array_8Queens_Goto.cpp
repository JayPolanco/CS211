/*Objective: Find all Possible placements of Queens on an 8x8 board
             such that no Queens are killed by another queens with 1D array
*/
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int board[8], col = 0, solutions = 0;
    board[0] = 0;

    nextCol: col++;
            if( col==8) goto print;
            board[col] = -1;

    nextRow: board[col]++;
            if(board[col] == 8)
                goto backtrack;
            for (int i = 0; i < col; ++i)
                if (board[i] == board[col] || (col-i) == abs(board[col]-board[i]))
                        goto nextRow;

                goto nextCol;

    backtrack: col--;
               if(col== -1) return 0;
               goto nextRow;

    print:
            cout << "Solution Number " << ++solutions << endl;

            for(int col = 0; col < 8; col++){
                cout << board[col];
            }
            cout << endl << endl;



           goto backtrack;

}
