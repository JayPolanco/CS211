/*Objective: Calculate how many solutions exist for queen placements
             on a 1x1 to an NxN board
             such that no Queens are killed by another queen
             (n is a user input)
*/
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

bool ok(int q[], int c) {
     for(int i = 0; i < c; i++){
        //Checks if there is a queen on same row or coloumn.
        if(q[i] == q[c] || (c-i) == abs(q[c]-q[i])){
            return false;
        }
    }
    return true;

}
// This function should return the number of solutions for the given board size.
int nqueens(int n) {
	// Dynamically declare an array of size n and initialize the first element to 0.
	int counter = 0, c = 0;
	int* q = new int[n];
	q[0]= 0;

   // You don't need to print the solutions.  Just increment a counter each time you find a solution.
   // Reuse the code from your 1D 8 queens program to find the solutions (you may have to make changes).
    bool from_backtrack=false;
    while(true){
        //next col
        while(c<n){
            if(!from_backtrack){
                c++;
                if(c==n)
                    break;
                q[c] = -1;


            }
            from_backtrack=false;

            while(q[c]<n){
                q[c]++;
                if(q[c] == n){
                     c--;
    				 if(c == -1)
        				return counter;
                     from_backtrack=true;
                }

                if(ok(q, c))
                     break;




            }
        }
        counter++;
        c--;
    	if(c == -1)
        	return counter;
        from_backtrack=true;

    }
	delete [] q;
   	return counter;



}

int main() {
   int n;
   cout << "How many Queens?  ";
   cin >> n;
   for (int i = 1; i <= n; ++i)
      cout << "There are " << nqueens(i) << " solutions to the " << i << " queens problem.\n";
   return 0;
}

