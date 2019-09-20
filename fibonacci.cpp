#include<iostream>
using namespace std;
int main()
{
	int a = 0, b = 1,n;
	cin >> n;
	if (n == 0)
		cout << n;
	else {
		for (int i = 0; i < n; i++)
		{
			int temp;
			temp = a+b;
			a = b;
			b = temp;
		}

		cout << a;
	}
	return(0);
}