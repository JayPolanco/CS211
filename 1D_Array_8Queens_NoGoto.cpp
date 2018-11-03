/*Objective: Find all Possible placements of Queens on an 8x8 board
             such that no Queens are killed by another queens with No Goto
*/
#include <iostream>
#include<cstdlib>
#include <cmath>

using namespace std;
bool ok(int q[], int col){
    for(int i = 0; i < col; i++){
        //Checks if there is a queen on same row or coloumn.
        if(q[i] == q[col] || (col-i) == abs(q[col]-q[i])){
            return false;
        }
    }
    return true;

}
void backtrack(int &col){
    col--;
    if(col == -1)
        exit(1);
}
void print(int q[]){
    for(int c = 0; c < 8; c++){
        cout << q[c];
    }
    cout << endl;

}

int main(){
    int q[8]; q[0]=0;
    int solution= 0;
    /*board setup section*/
    int c=0;
    bool from_backtrack=false;
    while(true){
        //next col
        while(c<8){
            if(!from_backtrack){
                c++;
                if(c==8)
                    break;
                q[c] = -1;


            }
            from_backtrack=false;

            while(q[c]<8){
                q[c]++;
                if(q[c] == 8){
                     backtrack(c);
                     from_backtrack=true;
                }

                if(ok(q, c))
                     break;




            }
        }
        cout << "solution# " <<++solution << endl;
        print(q);
        cout << endl;
        backtrack(c);
        from_backtrack=true;
    }
}
