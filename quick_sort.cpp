#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

int partition2(vector<int> &a, int l, int r, int &i, int &j) {
	int pivot = a[r];
	int lt = l;
	int reader = l;/*thus will traverse through the array*/
	int gt = r;
	if (r - l <= 1)
	{
		if (a[r] < a[l])
			swap(a[r], a[l]);
		i = l;
		j = r;

	}

	while (reader < gt)
	{
		if (a[reader] < pivot)
		{
			swap(a[reader], a[lt]);
			reader++;
			lt++;
		}
		else if (a[reader] > pivot)
		{
			swap(a[reader], a[gt]);
			gt--;
		}
		else
			reader++;
	}
	i = lt - 1;
	j = reader;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
	if (l >= r) {
		return;
	}
	int i, j;

	partition2(a, l, r, i, j);

	randomized_quick_sort(a, l, i);
	randomized_quick_sort(a, j, r);
}

int main() {
	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); ++i) {
		std::cin >> a[i];
	}
	randomized_quick_sort(a, 0, a.size() - 1);
	for (size_t i = 0; i < a.size(); ++i) {
		std::cout << a[i] << ' ';
	}
}
