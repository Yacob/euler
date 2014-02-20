#include <gmp.h>
#include <gmpxx.h>
#include <iostream>
#include <sstream>

using namespace std;

int main(){
	mpz_class bigNum;
	stringstream ss;
	mpz_ui_pow_ui(bigNum.get_mpz_t(), 2, 1000);
	ss << bigNum;
	string fish;
	ss >> fish;
	int digitSum = 0;
	for(int i = 0; i < fish.length(); i++){
		digitSum += ((int)fish.at(i) - 48);
	}
	cout << digitSum << endl;;

	return 0;
}
