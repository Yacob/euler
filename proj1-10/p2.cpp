//Project 2
//Find sum of even fibonnaci sequence numbers < 4000000


#include <iostream>
#include <vector>

using namespace std;

int main(){
	unsigned int sum = 2;
	vector<unsigned int> fib;
	fib.push_back(1);
	fib.push_back(2);
	
	unsigned int index = 2;
	unsigned int next_fib = 0;
	while(next_fib < 4000000){
		
		if(next_fib % 2 == 0){
			sum += next_fib;
		}

		next_fib = fib[index - 1] + fib[index - 2];
		fib.push_back(next_fib);
		index++;

	}
	cout << sum << endl;

	return 0;
}
