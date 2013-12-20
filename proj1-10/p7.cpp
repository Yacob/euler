//Project 7
//What is the 10 001st prime number?


#include <iostream>
#include <vector>

using namespace std;

int main(){

	vector<unsigned int> primes;
	primes.push_back(2);
	unsigned int num = 3;
	bool isPrime = true;
	while(primes.size() < 10001){
		isPrime = true;
		for(unsigned int i = 0; i < primes.size(); i++){
			if(num % primes[i] == 0){
				isPrime = false;
				break;
			}
		}
		if(isPrime){
			primes.push_back(num);
		}
		num++;
	}

	cout << primes.back() << endl;

	return 0;
}
