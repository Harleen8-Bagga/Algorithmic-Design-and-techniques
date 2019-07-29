#include<iostream>
using namespace std;
long long MaxPairwiseProductFast(long long  numbers[], int n)
{
	int max_index1 = -1;
	for (int i = 0; i < n; i++)
	{
		if ((max_index1 == -1) || (numbers[i] > numbers[max_index1]))
			max_index1 = i;
	}
	int max_index2 = -1;
	for (int j = 0; j < n; j++)
	{
		if ((j != max_index1) && ((max_index2 == -1) || (numbers[j] > numbers[max_index2])))
			max_index2 = j;
	}
	return((long long)(numbers[max_index1] * numbers[max_index2]));
}
int main()
{
	int n; long long *arr;
	cin >> n;
	arr = new long long[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	long long result = MaxPairwiseProductFast(arr, n);
	cout << result;
	delete(arr);
	return(0);
}