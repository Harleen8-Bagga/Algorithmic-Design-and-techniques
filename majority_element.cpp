#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  int lef_element = get_majority_element(a, left, (left + right - 1) / 2+1);
  int rig_element = get_majority_element(a, (left + right - 1) /2+1, right);
  int lcount = 0;
  for (int i = left; i < right; i++)
  {
	  if (a[i] == lef_element)
		  lcount++;
  }
  if (lcount > (right - left) / 2)/*if majority is greter than n/2*/
  return(lef_element);
  int rcount = 0;
  for (int i = left; i < right; i++)
  {
	  if (a[i] == rig_element)
		  rcount++;
  }
  if (rcount > (right - left) / 2)
	  return(rig_element);
  
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
