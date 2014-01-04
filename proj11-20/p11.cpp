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

	vector< vector<int> > grid;
	//read in grid and stuff
	while(infile.good()){
		vector<int> row;
		string nums = "";
		getline(infile, nums);
		istringstream convert(nums);
		copy(istream_iterator<int>(convert),
				istream_iterator<int>(),
				back_inserter(row));
		grid.push_back(row);
	}
	grid.pop_back();
	//find largest product of four adjacent nums
	//going in brute force style
	int temp_sum = 0;
	int sum = 0;
	//nums holds the numbers in the grid that create the largest product
	vector<int> nums;
	/*
	for(int i = 0; i < grid.size(); i++){
		for(int j = 0; j < grid[i].size(); j++){
			cout << grid[i][j] << " ";
		}
	}
	*/
	for(int i = 0; i < grid.size(); i++){
		for(int j = 0; j < grid[i].size(); j++){
			//horizontal
			if((j + 3) < grid[i].size()){
				temp_sum = (grid[i][j] * grid[i][j + 1] * 
						grid[i][j + 2] * grid[i][j + 3]);
				if(temp_sum > sum){
					sum = temp_sum;
					nums.clear();
					nums.push_back(grid[i][j]);
					nums.push_back(grid[i][j+1]);
					nums.push_back(grid[i][j+2]);
					nums.push_back(grid[i][j+3]);
				}
			}
			//vertical
			if((i + 3) < grid.size()){
				temp_sum = (grid[i][j] * grid[i + 1][j] *
						grid[i + 2][j] * grid[i + 3][j]);
				if(temp_sum > sum){
					sum = temp_sum;
					nums.clear();
					nums.push_back(grid[i][j]);
					nums.push_back(grid[i+1][j]);
					nums.push_back(grid[i+2][j]);
					nums.push_back(grid[i+3][j]);
				}
			}
			//forward diagonal
			if((i + 3) < grid.size() && j + 3 < grid[i].size()){
				temp_sum = (grid[i][j] * grid[i + 1][j + 1] *
						grid[i + 2][j + 2] * grid[i + 3][j + 3]);
				if(temp_sum > sum){
					sum = temp_sum;
					nums.clear();
					nums.push_back(grid[i][j]);
					nums.push_back(grid[i+1][j+1]);
					nums.push_back(grid[i+2][j+2]);
					nums.push_back(grid[i+3][j+3]);
				}
			}
			//backward diagonal
			if((i + 3) < grid.size() && j - 3 > 0){
				temp_sum = (grid[i + 3][j - 3] * grid[i + 2][j - 2] *
						grid[i + 1][j - 1] * grid[i][j]);
				if(temp_sum > sum){
					sum = temp_sum;
					nums.clear();
					nums.push_back(grid[i][j]);
					nums.push_back(grid[i + 1][j - 1]);
					nums.push_back(grid[i + 2][j - 2]);
					nums.push_back(grid[i + 3][j - 3]);
				}
			}
		}
	}
	cout << sum << endl;
	for(int i = 0; i < nums.size(); i++){
		cout << nums[i] << " ";
	}
	cout << endl;
	return 0;
}
