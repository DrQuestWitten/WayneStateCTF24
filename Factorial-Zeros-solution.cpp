#include <iostream>
#include <cmath>

using namespace std;

/**
 * Computes the divisor array.
 *
 * @param n Maximum index of divisor array.
 * @return array of length `n + 1` containing the smallest prime divisor at each index.
 */
long long* divisor_array(long long n) {
	// Each index contains the value of the smallest prime divisor of the index.
	// Element at index 0 contains the number of prime numbers.
	// Element at index 1 contains the number of composite numbers.
	long long* divisor = new long long[n + 1];

	// Initialize array
	for (long long i = 0; i < n + 1; i++) {
		divisor[i] = 0;
	}

	// Sieve of Eratosthenes
	for (long long i = 2; i < n + 1; i++) {
		if (divisor[i] != 0) {
			divisor[1]++;
			continue;
		}

		divisor[i] = i;
		divisor[0]++;
		for (long long j = i; j < n + 1; j += i) {
			if (divisor[j] != 0) {
				continue;
			}

			divisor[j] = i;
		}
	}

	return divisor;
}

/**
 * Computes an array of primes.
 *
 * @param divisor Divisor array.
 * @return array containing all the primes in the `divisor` array.
 */
long long* primes_from_divisor_array(const long long* divisor, long long n) {
	// primes at index i contains the ith prime number starting at 2 with i = 0.
	long long number_of_primes = divisor[0];
	long long* primes = new long long[number_of_primes];

	for (long long i = 0, j = 1; i < number_of_primes && j < n + 1; j++) {
		if (divisor[j] == j) {
			primes[i] = j;
			i++;
		}
	}

	return primes;
}

/**
 * Computes the array of prime factors.
 *
 * @param primes Primes up to `n`.
 * @param number_of_primes number of primes up to `n`.
 * @param n Number which serves as the argument for the factorial.
 * @return computes the array of prime factors of `n`!.
 */
long long* factorial_prime_factorization_from_primes(const long long* primes, long long number_of_primes, long long n) {
	long long* factorial_prime_factorization = new long long[number_of_primes];

	for (long long i = 0; i < number_of_primes; i++) {
		long long prime_power = 0;
		for (long long j = 1; pow(primes[i], j - 1) <= n; j++) {
			prime_power += n / pow(primes[i], j);
		}
		factorial_prime_factorization[i] = prime_power;
	}

	return factorial_prime_factorization;
}

/**
 * Computes the array of prime factors.
 *
 * @param primes Primes
 * @param number_of_primes Number of primes.
 * @param b Number which will be factored
 * @return computes the array of prime factors of `b`.
 */
long long* prime_factorization_from_primes(const long long* primes, long long number_of_primes, long long b) {
	long long* prime_factorization = new long long[number_of_primes];

	for (long long i = 0; i < number_of_primes; i++) {
		long long number = primes[i];
		long long prime_power = 0;
		for (long long j = 0; b % number == 0; j++) {
			prime_power++;
			number *= primes[i];
		}
		prime_factorization[i] = prime_power;
	}

	return prime_factorization;
}


/**
 * Computes the sum of the number of trailing zeros.
 *
 * @param b_lower_bound Number base lower bound.
 * @param b_upper_bound Number base upper bound.
 * @param n Number which serves as the argument for the factorial.
 * @return sum of the number of trailing zeros in the base `b`-representation of `n`! where b ranges from `b_lower_bound` to `b_upper_bound` inclusive.
 */
long long sum_factorial_trailing_zeros(long long b_lower_bound, long long b_upper_bound, long long n) {
	long long* divisor = divisor_array(n);

	long long number_of_primes = divisor[0];

	long long* primes = primes_from_divisor_array(divisor, n);

	long long* factorial_n_prime_factorization = factorial_prime_factorization_from_primes(primes, number_of_primes, n);

	long long sum = 0;
	
	for (long long b = b_lower_bound; b <= b_upper_bound; b++) {
		long long* b_prime_factorization = prime_factorization_from_primes(primes, number_of_primes, b);

		long long min = LLONG_MAX;
		for (long long i = 0; i < number_of_primes; i++) {
			if (b_prime_factorization[i] != 0 && factorial_n_prime_factorization[i] / b_prime_factorization[i] < min) {
				min = factorial_n_prime_factorization[i] / b_prime_factorization[i];
			}
		}
		sum += min;
	}

	return sum;
}

int main() {
	const long long b_lower_bound = 2;
	const long long b_upper_bound = 1000;
	const long long n = 1000000;

	cout << sum_factorial_trailing_zeros(b_lower_bound, b_upper_bound, n) << endl; // 47737877
}
