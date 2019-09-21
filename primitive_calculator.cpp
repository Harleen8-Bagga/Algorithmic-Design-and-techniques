
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
/*below mentioned is dynamic programming approach*/
vector<int>DP(int n) {
	std::vector<int>dp(n+1);/*by default the elemnts decalred by vector are al intialised to zero*/
	std::vector<int> sequence;
	
	for (int i = 1; i <= n; i++)
	{
		dp[i] = 1 + dp[i - 1];

		if (i % 2 == 0) dp[i] = std::min(dp[i], 1 + dp[i / 2]);

		if (i % 3 == 0) dp[i] = std::min(dp[i], 1 + dp[i / 3]);


	}
	int j = n;
	while (j>=n)
	{
		sequence.push_back(j);
		if (dp[j] - 1 == dp[j - 1])
			j = j + 1;
		else if (j%2==0 && (dp[j] - 1 == dp[j / 2]))
			j = j * 2;
		else if(j%3==0 && (dp[j]-1 == dp[j/3]))
			j = j * 3;
		
	}
	sequence.push_back(1);
	reverse(sequence.begin(), sequence.end());
	return(sequence);
}

vector<int> optimal_sequence(int n) {
	std::vector<int> sequence;
	while (n >= 1) {
		sequence.push_back(n);
		if (n % 3 == 0) {
			n /= 3;
		}
		else if (n % 2 == 0) {
			n /= 2;
		}
		else {
			n = n - 1;
		}
	}
	reverse(sequence.begin(), sequence.end());
	return sequence;
}

int main() {
	int n;
	std::cin >> n;
	vector<int> sequence = DP(n);
	std::cout << sequence.size() - 1 << std::endl;
	for (size_t i = 0; i < sequence.size(); ++i) {
		std::cout << sequence[i] << " ";
	}
}

	