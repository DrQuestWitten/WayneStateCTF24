#include <iostream>

using namespace std;

/**
 * Computes the sum of the non-zero even-valued fibonacci numbers.
 *
 * @param exponent Value that 2 will be raised by.
 * @param modulus Value that will mod the result.
 * @return sum of the first 2^`exponent` non-zero even-valued fibonacci numbers modulo `modulus`.
 */
long long sum_even_fibonacci(long long exponent, long long modulus) {
	long long A_1_1 = 4, A_1_2 = 1, A_2_1 = 1, A_2_2 = 0;

	long long two_inverse = modulus / 2 + 1;

	for (int i = 0; i < exponent; i++) {
		long long temp_A_1_1 = A_1_1, temp_A_1_2 = A_1_2, temp_A_2_1 = A_2_1, temp_A_2_2 = A_2_2;

		A_1_1 = ((temp_A_1_1 * temp_A_1_1) % modulus + (temp_A_1_2 * temp_A_2_1) % modulus) % modulus;
		A_1_2 = ((temp_A_1_1 * temp_A_1_2) % modulus + (temp_A_1_2 * temp_A_2_2) % modulus) % modulus;
		A_2_1 = ((temp_A_1_1 * temp_A_2_1) % modulus + (temp_A_2_1 * temp_A_2_2) % modulus) % modulus;
		A_2_2 = ((temp_A_1_2 * temp_A_2_1) % modulus + (temp_A_2_2 * temp_A_2_2) % modulus) % modulus;
	}

	long long sum = (two_inverse * ((5 * A_2_1) % modulus + A_2_2 - 1) % modulus) % modulus;

	return sum;
}

int main() {
	const long long exponent = 1024;
	const long long mod = 1000000007;

	cout << sum_even_fibonacci(exponent, mod) << endl; // 186311468
}
