#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here
  for (int i = 0; i < n; i++)
  {
	  n -= i;
	  if (n <= 0)
		  summand.push_back(n+i);
	  if (n == 0)
	  {
		  summands.push_back(i);
		  break;
	  }
	  else
		  summand.push_back(i);

  }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
