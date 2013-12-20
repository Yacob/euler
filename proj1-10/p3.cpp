//Project 3
//Find largest prime factor of 600851475143


#include <iostream>
#include <vector>

using namespace std;


int main(){


	unsigned long big_num = 600851475143;
	vector<unsigned int> primes;
	primes.push_back(2);
	bool is_prime = true;

	for(unsigned int i = 3; i < big_num; i++){
		is_prime = true;
		for(unsigned int j = 0; j < primes.size(); j++){
			if(i % primes[j] == 0){
				is_prime = false;
				break;
			}
		}
		if(is_prime){
			primes.push_back(i);
			if(big_num % i == 0){
				big_num /= i;
			}
		}
	}
	cout << big_num << endl;
	return 0;
}
