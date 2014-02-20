#include <vector>
#include <iostream>

using namespace std;

int main(){
	vector< vector<unsigned long> >grid;
	vector<unsigned long> outer(21,1);
	grid.push_back(outer);
	for(int i = 0; i < 20; i++){
		vector<unsigned long> inny(21,0);
		inny[0] = 1;
		grid.push_back(inny);
	}
	for(int i = 1; i < 21; i++){
		for(int j = 1; j < 21; j++){
			grid[i][j] = (grid[i - 1][j] + grid[i][j - 1]);
		}
	}
	
	for(int i = 0; i < grid.size(); i++){
		for(int j = 0; j < grid[i].size(); j++){
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
	cout << grid[20][20] << endl;


	return 0;
}
