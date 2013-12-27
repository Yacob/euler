//Project 10
//Find the sum of all primes below 2000000


#include <vector>
#include <iostream>

using namespace std;

int main(){
	vector<unsigned long long> primes;
	primes.push_back(2);
	bool is_prime = true;
	unsigned long long sum = 2;
	for(unsigned long long i = 3; i < 2000000; i++){
		is_prime = true;
		for(unsigned long long j = 0; j < primes.size(); j++){
			if(i % primes[j] == 0){
				is_prime = false;
				break;
			}
		}
		if(is_prime){
			primes.push_back(i);
			sum += i;
			cout << i << endl;
		}
	}
	cout << sum << endl;


	return 0;
}
