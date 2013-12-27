//Project 11
//Find largest product of four adjacent numbers

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>


using namespace std;

int main(){

	ifstream infile;
	infile.open("p11.txt");

	vector< vector< unsigned int> > grid;
	//read in grid and stuff
	while(infile.good()){
		vector<unsigned int> row;
		string nums = "";
		getline(infile, nums);
		istringstream convert(nums);
		copy(istream_iterator<unsigned int>(convert),
				istream_iterator<unsigned int>(),
				back_inserter(row));
		grid.push_back(row);
	}
	//find largest product of four adjacent nums
	//going in brute force style
	unsigned int temp_sum = 0;
	unsigned int sum = 0;
	for(unsigned int i = 0; i < grid.size(); i++){
		for(unsigned int j = 0; j < grid[i].size(); j++){
			//stuff
		}
	}

	return 0;
}
