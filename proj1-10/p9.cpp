//Project 9
//There exists a < b < c such that a^2 + b^2 = c^2 and a + b + c = 1000


#include <vector>
#include <iostream>

using namespace std;

int main(){
	for(unsigned int a = 1; a < 333; a++){
		for(unsigned int b = a + 1; b < 500; b++){
			for(unsigned int c = b + 1; c < 1000; c++){
				if(a + b + c == 1000){
					if((a*a + b*b) == c*c){
						cout << a << " " << b << " " << c << endl;
						cout << "with product " << a * b * c << endl;
						return 0;
					}
				}
			}
		}
	}
	return 0;
}
