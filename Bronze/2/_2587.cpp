#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int* arr = new int[5];
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr, arr + 5);
	cout<< sum / 5<<"\n";
	cout<< arr[2];
	return 0;
}