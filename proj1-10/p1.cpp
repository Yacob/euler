//Project 1
//Find sum of all multiples of 3 or 5 below 1000.

#include <iostream>
#include <vector>

using namespace std;

int main(){
	int sum = 0;
	for(int i = 0; i < 1000; i++){
		if(i % 3 == 0 || i % 5 == 0){
			sum += i;
		}
	}
	cout << sum << endl;
	return 0;
}
