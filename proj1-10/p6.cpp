//Project 7
//Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.



#include <iostream>
#include <vector>

using namespace std;

int main(){
	unsigned long sum_squares = 0;
	unsigned long square_sums = 0;
	
	for(unsigned long i = 1; i < 101; i++){
		sum_squares += (i * i);
		square_sums += i;
	}

	square_sums *= square_sums;
	
	cout << square_sums - sum_squares << endl;


	return 0;
}
