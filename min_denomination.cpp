#include<iostream>
using namespace std;
/*coin denomination problem*/
void mergeSortedSubarrays(int a[], int start, int mid, int end);
void mergeSort(int a[], int start, int end)
{
	if (end == start + 1)
		return;
	int mid = (start + end) / 2;
	mergeSort(a, start, mid);
	mergeSort(a, mid, end);
	mergeSortedSubarrays(a, start, mid, end);

}
void mergeSortedSubarrays(int a[], int start, int mid, int end)
{
	int i, j, tempA[3], index = start;
	for (i = start, j = mid; (i < mid || j < end);)
	{
		if ((i < mid) && (j < end)) {
			if (a[j] > a[i])
			{
				tempA[index] = a[j];
				j++;
			}
			else
			{
				tempA[index] = a[i];
				i++;

			}
		}
		else {
			if (i < mid)
			{
				tempA[index] = a[i];
				i++;
			}
			else
			{
				tempA[index] = a[j];
				j++;
			}


		}
		index++;

	}
	for (i = start; i < end; i++)
	{
		a[i] = tempA[i];
	}
}
int min_coins(int a[], int n, int amount)
{
	int count = 0, i;
	for (i = 0; i < n; i++)
		while (amount >= a[i])
		{
			amount = amount - a[i];
			count++;
		}
	return(count);
}
int main()
{
	int a[] = { 1,5,10 }, m, c;
	mergeSort(a, 0, 3);
	cin >> m;
	c = min_coins(a, 3, m);
	cout << c;
	return(0);

}
