//Project 8
//Find the greatest product of five consecutive digits in the number from p8.txt


#include <iostream>
#include <deque>
#include <fstream>

using namespace std;

int main(){
	unsigned int product = 1;
	unsigned int max_product = 1;
	deque<unsigned int> consec;
	ifstream infile;
	infile.open("p8.txt");
	for(unsigned int i = 0; i < 5; i++){
		int digit = infile.get() - 48; //reads in ascii value of number. '0' = 48
		product *= digit;
		consec.push_back(digit);
	}
	max_product = product;
	while(infile.good()){
		int digit = infile.get();
		if(digit >= 48){
			digit -= 48;
			if(product == 0){
				consec.push_back(digit);
				consec.pop_front();
				product = 1;
				for(unsigned int i = 0; i < consec.size(); i++){
					product *= consec[i];
				}
			}
			else {
				product *= digit;
				product /= consec.front();
				consec.pop_front();
				consec.push_back(digit);
			}
			if(product > max_product){
				max_product = product;
			}
		}
	}
	cout << max_product << endl;

	return 0;
}
