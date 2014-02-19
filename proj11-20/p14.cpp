/* Longest Collatz Sequence
 * The following iterative sequence is defined for the set of positive integers:
 *
 * n → n/2 (n is even)
 * n → 3n + 1 (n is odd)
 *
 * Using the rule above and starting with 13, we generate the following sequence:
 *
 * 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
 * It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
 *
 * Which starting number, under one million, produces the longest chain?
 *
 * NOTE: Once the chain starts the terms are allowed to go above one million.
 */

#include <vector>
#include <iostream>
#include <string>
#include <gmp.h>
#include <gmpxx.h>

using namespace std;

mpz_class collatz(mpz_class start){
	mpz_class length = 1;
	while(mpz_cmp_ui(start.get_mpz_t(), 1) != 0){
		if(mpz_even_p(start.get_mpz_t()) != 0){
			mpz_divexact_ui(start.get_mpz_t(), start.get_mpz_t(), 2);
		}
		else {
			mpz_mul_ui(start.get_mpz_t(), start.get_mpz_t(), 3);
			mpz_add_ui(start.get_mpz_t(), start.get_mpz_t(), 1);
		}
		length++;
	}
	return length;
}

int main(){
	mpz_class collatzLength = 1;
	mpz_class temp;
	mpz_class sequenceStart;
	for(mpz_class i = 2; i < 1000000; i++){
		temp = collatz(i);
		if(temp > collatzLength){
			collatzLength = temp;
			sequenceStart = i;
		}
	}
	cout << collatzLength << endl;
	return 0;
}
