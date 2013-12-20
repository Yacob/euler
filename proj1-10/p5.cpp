//Project 5
//Find smallest number divisible by 1...20 evenly
//Since 1...10 divides 11...20 we will only check 11...20


#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<unsigned int> factors;
	for(unsigned int i = 11; i < 21; i++){
		factors.push_back(i);
	}

	cout << "while thinking about an efficient way I realized that it is " + 
		"just 1 * 2 * 2 * 2 * 2 * 3 * 3 * 5 * 7 * 11 * 13 * 17 * 19 " << endl;
	cout << "because you can form each 1...20 using a product of prime factors" << endl;
	//sadly no code for this one.
	//I was thinking about what kind of reasonable bounds you would use and arrived
	//at the answer to partway through writing this.
	//If I were to finish it I would just iterate though incremently by 
	//20 * 19 * 17 * 13 * 11 since the primes and 20 all had to be a part of the answer
	//by knowledge of gcd(a,b) = 1 => lcm(a,b) = a*b
	//I would have to change vector factors to only include {12 14 15 16 18}

	return 0;
}
