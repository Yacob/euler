//Maximum path sum I

#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

int main(){
	
	//read data in
	ifstream infile;
	infile.open("p18.txt");
	int line = 1;
	vector< vector<int> > triangle;
	while(!infile.eof()){
		vector<int> nums;
		for(int i = 0; i < line; i++){
			int num;
			infile >> num;
			nums.push_back(num);
		}
		line++;
		triangle.push_back(nums);
	}
	triangle.pop_back();


	int bot = triangle.size() - 1;
	int num_iter = triangle.size();
	for(int q = 0; q < num_iter - 1; q++){
		vector<int> improved;
		for(int i = 0; i < triangle[bot].size() - 1; i++){
			if(triangle[bot][i] > triangle[bot][i+ 1]){
				improved.push_back(triangle[bot][i]);
			}
			else {
				improved.push_back(triangle[bot][i + 1]);
			}
		}
		triangle.pop_back();
		bot--;
		for(int i = 0; i < triangle[bot].size(); i++){
			triangle[bot][i] += improved[i];
			cout << triangle[bot][i] << " ";
		}
		cout << endl;
	}
	return 0;
}
