#include <iostream>
#include <cassert>
#include <vector>

using std::vector;
int binary_search_run(const vector<int> &a, int left, int right, int x);

int binary_search(const vector<int> &a, int x,int left,int right) {
	int left = 0, right = (int)a.size();
	//write your code here
	return binary_search_run(a, left, right, x);
}
int binary_search_run(const vector<int> &a, int left, int right, int x)
{
	while (right >= left)
	{
		int mid = left + (right - left) / 2;
		if (x == a[mid])
			return(mid);
		else if (x < [mid])
			right = mid - 1;
		else
			left = mid + 1;
	}

	return(-1);s

}

/*int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
	if (a[i] == x) return i;
  }
  return -1;
}*/

int main() {
	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); i++) {
		std::cin >> a[i];
	}
	int m;
	std::cin >> m;
	vector<int> b(m);
	for (int i = 0; i < m; ++i) {
		std::cin >> b[i];
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < m; ++i) {
		//replace with the call to binary_search when implemented
	   /* std::cout << linear_search(a, b[i]) << ' ';*/

		std::cout << binary_search(a, b[i]) << ' ';
	}
}
