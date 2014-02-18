//Project 13 (large sum)
//find first ten digits of sum of the following 100 50-digit numbers

//need to make something to add the numbers
//store each number as char array and create new char array of numbers for addition

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <gmp.h>
#include <gmpxx.h>


using namespace std;


int main(){

	vector<string> numbers;
	
	ifstream infile;
	infile.open("p13.txt");
	while(infile.good()){	//read in text file of numbers
		string nums = "";
		getline(infile, nums);
		numbers.push_back(nums);
	}
	numbers.pop_back();	//read in empty newline at end of p13.txt
	mpz_class *bigNums = new mpz_class[numbers.size()];
	for(int i = 0; i < numbers.size(); i++){
		mpz_class num;
		mpz_set_str(num.get_mpz_t(), numbers[i].c_str(), 10);
		bigNums[i] = num;
	}
	
	mpz_class total;
	total = 0;
	for(int i = 0; i < numbers.size(); i++){
		mpz_add(total.get_mpz_t(), total.get_mpz_t(), bigNums[i].get_mpz_t());
	}
	
	cout << total << endl;

	return 0;
}
