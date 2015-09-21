
#define NUM_PRIMES 250

int binarySearch (int key, int *haystack, int start, int end) {
	int cur = (start + end) / 2;

	if (start == cur) return 0;

	if (key < haystack[cur]) {
		return binarySearch (key, haystack, start, end - 1);	
	}

	if (key > haystack[cur]) {
		return binarySearch (key, haystack, cur + 1, end);
	}

	if (key == haystack[cur]) return 1;
}

int main () {
	//The variable n corresponds to the number of prime numbers
	//The variable i corresponds to the current number
	int prime_ar[NUM_PRIMES];
	int n = 0, i = 2, chosen, validate = 1;

	while (n < NUM_PRIMES) {
		int count = 0;
		int j = 0;

		while (j < n) {
			if (i % prime_ar[j] == 0) count++;
			if (count > 1) break;
			
			j++;
		}

		if (count < 1) {
			prime_ar[n] = i;
			n++;
		}

		i++;
	}

	while (validate) {
		std::cout << "Please enter a number to test: ";
		std::cin >> chosen;
		
		if (chosen == 0) validate = 0;

		if (validate) {
			if (binarySearch (chosen, prime_ar, 0, sizeof (prime_ar) / sizeof (int))) {
				std::cout << chosen << " is a prime number." << std::endl;
			}
			else {
				std::cout << chosen << " is not a prime number." << std::endl;
			}
		}
	}

	return 0;
}
