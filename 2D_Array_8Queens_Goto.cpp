/*Objective: Find all Possible placements of Queens on an 8x8 board
             such that no Queens are killed by another queens
*/
#include <iostream>
using namespace std;

int main(){
    int board[8][8] = {}, row,col = 0, i;
    board[0][0] = 1;
    int solution = 0;

    nextCol: col++;
            if( col==8) goto print;
            row = -1;
    nextRow: row++;
            if(row == 8)
                goto backtrack;
            //row test
            for(i = 0; i < col; i++)
                if(board[row][i] == 1) goto nextRow;
            //up diagonal test
            for(i = 1; (row-i)>=0 && (col-i) >= 0; i++){
                if(board[row-i][col-i] == 1)
                    goto nextRow;
            }
            //down diagonal test
            for(i = 1; (row+i)<8 && (col -i) >= 0; i++){
                if(board[row+i][col-i] ==1)
                    goto nextRow;
            }
            board[row][col]=1;
            goto nextCol;
    backtrack: col--;
               if(col== -1) return 0;
               row = 0;
               while(board[row][col]!=1)
                    row++;
               board[row][col]=0;
               goto nextRow;

    print:
            cout <<"Solution " << ++solution << endl;
            for(int row = 0; row < 8; row++){
                for(int col = 0; col < 8; col++){
                   cout << board[row][col];
               }
                cout << endl;
            }
            cout << endl;



           goto backtrack;

}
