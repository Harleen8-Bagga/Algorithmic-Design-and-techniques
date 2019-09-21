#include <iostream>
#include <string>
#include<vector>


using std::string;
using std::vector;

int edit_distance(const string &str1, const string &str2) {
	//write your code here
	int m = str1.size();
	int n = str2.size();
	vector<vector <int> >v(m + 1, vector<int>(n + 1, 0));
	for (int i = 0; i <= m; ++i)/*intialising first row*/
	{
		v[i][0] = i;
	}
	for (int k = 0; k <= n; ++k)/*intialising first column*/
	{
		v[0][k] = k;
	}
	int cost = 0;
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (str1[i - 1] == str2[j - 1])/*if last elemnt of both strings equal*/
				cost = 0;
			else
				cost = 1;
			v[i][j] = std::min(std::min(v[i - 1][j], v[i][j - 1]) + 1, v[i - 1][j - 1] + cost);/*delete,add,replace*/

		}
		return(v[m][n]);
	}



	return 0;
}

int main() {
	string str1;
	string str2;
	std::cin >> str1 >> str2;
	std::cout << edit_distance(str1, str2) << std::endl;
	return 0;
}
