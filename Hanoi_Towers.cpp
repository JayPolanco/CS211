/*Objective: Solve the Hanoi Towers Problem with
             the number of rings as user inputs*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<int> t[3];
	int from, move =0, n, to, candidate;
	cout << "Please enter the number of rings to move: ";
	cin >> n;
	for(int i = n+1; i >= 1; i--)
		t[0].push_back(i);
	t[1].push_back(n+1);
	t[2].push_back(n+1);

	from = 0;
	candidate =1;
	if(n%2!=0){

		to=1;

		while(t[1].size() != n+1){
			cout << "Move #" << ++move << ": Transfer ring " << candidate << " from tower " << char(from+'A') << " to tower " << char(to+'A') << "\n";

			t[from].pop_back();
			t[to].push_back(candidate);
				if(t[(to+1)%3].back() < t[(to + 2)%3].back())
					from = (to+1)%3;
				else
					from = (to+2)%3;
				if(t[(from)%3].back() < t[(from+1)%3].back())
					to = (from + 1)%3;
				else
					to = (from + 2)%3;
				candidate=t[from].back();
		}
	}

	else{

		to = 2;

		while(t[1].size() != n+1){
			cout << "Move #" << ++move << ": Transfer ring " << candidate << " from tower " << char(from+'A') << " to tower " << char(to+'A') << "\n";
			t[from].pop_back();
			t[to].push_back(candidate);
			if(t[(to+1)%3].back() < t[(to + 2)%3].back())
				from = (to+1)%3;
			else
				from = (to+2)%3;
			if(t[(from)%3].back() < t[(from+2)%3].back())
				to = (from + 2)%3;
			else
				to = (from + 1)%3;
			candidate=t[from].back();
		}
	}
	return 0;
}






