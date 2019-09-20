#include <iostream>
using namespace std;

int get_pisano_period(int m) {
	unsigned long long a = 0, b = 1, c = a + b;
	for (int i = 0; i < m * m; i++) {
		c = (a + b) % m;
		a = b;
		b = c;
		if (a == 0 && b == 1) return i + 1;
	}
}

int get_fibonacci_huge(long long n, int m) {
	unsigned long long remainder = n % get_pisano_period(m);

	unsigned long long first = 0;
	unsigned long long second = 1;

	unsigned long long result = remainder;

	for (unsigned long long int i = 1; i < remainder; i++) {
		res = (first + second) % m;
		first = second;
		second = result;
	}

	return result % m;
}

int main() {

	unsigned long long int n; int g;
	std::cin >> n;
	g = get_fibonacci_huge(n + 2, 10);
	if (g == 0)
		std::cout << 9;
	else
		std::cout << g - 1 << '\n';
}
