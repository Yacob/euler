//Project 12
//What is the value of the first triangle number to have over 500 divisors

#include <iostream>
#include <vector>

using namespace std;

unsigned int count_divisors(unsigned int num){
	vector<unsigned int> prime_factors;
	unsigned int composite = num;
	for(unsigned int i = 2; i <= (unsigned int)(num / 2); i++){
		while(composite % i == 0){
			prime_factors.push_back(i);
			composite /= i;
		}
	}
	//need to count the exponent.  ie if prime_factors is 2 2 2 3 4 4 need to find 3,1,2
	unsigned int expo = 1;
	vector<unsigned int> exponents;
	auto first = prime_factors.begin();
	auto last = prime_factors.end();
	auto second = first;
	second++;
	while(first != last){
		expo = 2;
		while(second != last && *first == *second){
			expo++;
			second++;
		}
		exponents.push_back(expo);
		first = second;
		second++;
	}
	expo = 1;
	for(unsigned int i = 0; i < exponents.size(); i++){
		expo *= exponents[i];
	}
	return expo; 
}


int main(){
	//create large list of triangle numbers
	vector<unsigned int> triangles;
	triangles.push_back(0);
	for(unsigned int i = 1; i < 1000000; i++){
		unsigned int next = (triangles[i - 1] + i);
		triangles.push_back(next);
	}
	//find number of factors
	for(unsigned int i = 0; i < triangles.size(); i++){
		//note that the first number with 500 factors is 50388480 = 2^9*3^9*5
		if(triangles[i] < 50388480){
			continue;
		}
		if(count_divisors(triangles[i]) >= 500){
			cout << triangles[i] <<  " " << count_divisors(triangles[i]) << endl;
			break;
		}
	}
	return 0;
}
