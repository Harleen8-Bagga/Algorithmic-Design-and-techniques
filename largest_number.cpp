#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>


using std::vector;
using std::string;
bool sorting(string a, string b) {
	string ab = a.append(b);/*here what we did was we appended a with b*/
	string ba = b.append(a);/*here we append b with a */
	return(ba < ab);/*if ab happens to be greater than ba then we return true else we return false*/
}

string largest_number(vector<string> a) {
  //write your code here
  std::stringstream ret;/*stringstream lets you read through a string*/
  sort(a.begin(), a.end(), sorting);
  for (size_t i = 0; i < a.size(); i++) {
	  ret << a[i];/*ret is reading each character of a[i]*/
  }
  string result;
  ret >> result;/*result is reating through the stream of characters present in ret*/
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
