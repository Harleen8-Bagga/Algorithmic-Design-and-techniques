#include <iostream>
using namespace std;

int get_change(int m, int coins[]) {
	//write your code here
	int *min_coins; int num_coins;
	min_coins = new int(m);
	min_coins[0] = 0;
	for (int i = 1; i <= m; i++)
	{
		min_coins[i] = 2000;
		for (int j = 0; j < 3; j++)
		{
			if (i >= coins[j])
				num_coins = min_coins[i - coins[j]] + 1;
			if (num_coins < min_coins[i])
				min_coins[i] = num_coins;
		}

	}

	return(min_coins[m]);
}

int main() {
	int m;
	int arr[] = { 2 };
	cin >> m;
	cout << get_change(m, arr) << '\n';
}
