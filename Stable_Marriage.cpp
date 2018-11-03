/*  Objective: Solve the Stable Marriage Problem*/
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

//mp males preference, wp women preference
bool ok(int q[], int c){
    static int mp[3][3] = {{0,2,1}, {0,2,1},{1,2,0}};
    static int wp[3][3] = {{2,1,0},{0,1,2},{2,0,1}};
	int new_man = c;
	int new_women = q[c];

    for(int i = 0; i < c; i++){
        if(q[i] == q[c]){
            return false;
    	}
    	int current_man = i;
    	int current_women = q[i];
//Checks if the current man prefers a new women more then his current wife and if that new women prefers the current man
        if((mp[current_man][new_women] < mp[current_man][current_women]) && (wp[new_women][current_man] < wp[new_women][new_man])){
            return false;
	// if( mp[i][q[c]] < mp[i][q[i]] &&
	// wp[q[c]][i] < wp[q[c]]
        }
//Checks if the current women prefers a new man more then her current man and if that new man prefers the current man women
        if((mp[new_man][current_women]< mp[new_man][new_women])&& (wp[current_women][new_man] < wp[current_women][current_man])){
        	return false;
        }
	// if(mp[c][q[i]] < mp[c][q[c]] &&
	// wp[q[i]][c] < wp[q[i]][i]

    }

    return true;
}


void backtrack(int &col){
    col--;
    if(col == -1){
        exit(1);
    }
}
//Print solution
void print(int q[]) {
   for (int i = 0; i < 3; ++i)
      cout << i << "\t" << q[i] << "\n";
   cout << "\n";
}

int main(){
    /*array setup section*/
    int q[3]; q[0]=0;
    int solution= 1;

    int c=0;
    bool from_backtrack=false;
    while(true){
        //next col
        while(c<3){
            if(!from_backtrack){
                c++;
                if(c==3)
                    break;
                q[c] = -1;


            }
            from_backtrack=false;

            while(q[c]<3){
                q[c]++;
                if(q[c] == 3){
                     backtrack(c);
                     from_backtrack=true;
                }

                if(ok(q, c))
                     break;




            }
        }
        cout << "solution# " <<solution << endl;
        print(q) ;
        solution = solution + 1;
        backtrack(c);
        from_backtrack=true;
    }
}
