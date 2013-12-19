//Project 4
//Find largest palindrome made from product of two 3 digit numbers


#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;


//see if num is palindrome
bool isPalindrome(unsigned int palin_num){
	//convert num to string
	ostringstream convert, backwards;
	convert << palin_num;
	string palin_string = convert.str();

	//reverse the palin_string
	for(auto rit = palin_string.rbegin(); rit != palin_string.rend(); ++rit){
		backwards << *rit;
	}
	string reversed = backwards.str();

	//check if equal after reversed
	if(palin_string.compare(reversed) == 0){
		return true;
	}
	else {
		return false;
	}
}


int main(){

	unsigned int max_palindrome = 0;
	unsigned int palindrome = 0;
	for(unsigned int i = 100; i < 1000; i++){
		for(unsigned int j = 100; j < 1000; j++){
			palindrome = (i * j);
			if(isPalindrome(palindrome) && palindrome > max_palindrome){
				max_palindrome = palindrome;
			}
		}
	}
	cout << max_palindrome << endl;
	
	return 0;
}
