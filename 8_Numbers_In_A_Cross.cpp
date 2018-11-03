/*Objective: Solve the 8 numbers in a cross problem*/

#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

bool okay(int cross[], int box){
    static int adj_table[8][5] = {
    {-1},
    {0, -1},
    {0, 1, -1},
    {0,2,-1},
    {1,2,-1},
    {1,2,3,4,-1},
    {2,3,5,-1},
    {4,5,6,-1}};

    //Same number test
    for(int i = 0; i < box; i++){
        if((cross[i] == cross[box])){
            return false;
        }
    }
    //Check if adjacent numbers are consecutive
    for(int i = 0; adj_table[box][i] != -1; i++) {
        if (abs(cross[adj_table[box][i]] - cross[box]) == 1){
            return false;
        }
    }
    return true;
}
//goes to previous box
void backtrack(int &col){
    col--;
    if(col == -1){
        exit(1);
    }
}
//Print solution
void print(int cross[]){
    for(int j = 0; j < 8; j++){
        cout << cross[j];
    }
    cout << endl;
}

int main() {
   int cross[8]; cross[0] = 1;
   int solution = 0, col = 0;


   bool from_backtrack = false;
   while(true){
          //columns = boxes
       while(col <= 8){
           if(!from_backtrack){
                col++;
                if(col == 8)
                    break;
                cross[col] = 0;
            }
           from_backtrack = false;
           //Value inside of box
           while(cross[col] < 9){
               cross[col]++;
               if(cross[col] == 9){
                   backtrack(col);
                   from_backtrack = true;
               }

               if(okay(cross, col))
                    break;
           }
       }
       cout << "solution#" << ++solution << endl;
       print(cross);
       backtrack(col);
       from_backtrack = true;
   }
}
