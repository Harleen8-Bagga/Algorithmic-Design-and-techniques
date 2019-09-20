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

	unsigned long long res = remainder;

	for (unsigned long long int i = 1; i < remainder; i++) {
		res = (first + second) % m;
		first = second;
		second = res;
	}

	return res % m;
}
long long get_fibonacci_partial_sum_naive(long long from, long long to) {
	if (from == 0)
		from = 1;
	int p=get_pisano_period(10);
	int sum_from=get_fibonacci_huge(from% p, 10);
	int sum_to = get_fibonacci_huge(to%p, 10);
	int partial_sum = sum_to - sum_from;
	return(partial_sum);

	}

	return ((partial_sum+10) % 10;
}

int main() {
	//    for (int i = 2; i < 100; i++) {
	//        std::cout << i << " : " << get_pisano_period(i) << std::endl;
	//    }
	//    return 0;
	unsigned long long int n; int g;
	std::cin >> n;
	g = get_fibonacci_huge(n + 2, 10);
	if (g == 0)
		std::cout << 9;
	else
		std::cout << g - 1 << '\n';
}