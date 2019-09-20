#include<iostream>
using namespace std;
long long int euclid(long long int a, long long int b)
{
	if (b == 0)
		return(a);
	else if (b == 1)
		return(b);
	else
	{
		return(euclid(b, a%b));

	}
}
int main()
{
	long long int a, b;
	cin >> a;
	cin >> b;
	long long int c = euclid(a, b);
	cout << (a*b)/c;
	return(0);


}