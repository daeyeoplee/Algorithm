#include <iostream>

/*
Sieve of Eratosthenes
this Algorithm is to get Prime numbers
the concept is to erase non Prime numbers(composition numbers)
*/

using namespace std;

int MAX = 100000;
int primes[100001];

void getPrime() {
	for (int i = 2; i <= MAX; i++) {
		if (primes[i] == -1)continue;
		for (int j = 2; i*j <= MAX; j++) {
			primes[i*j] = -1;
		}
	}

	for (int i = 2; i <= MAX; i++) {
		if (primes[i] != -1) cout << i << ' ';
	}
}

int main() {
	getPrime();
}