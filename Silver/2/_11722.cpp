#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	int* arr = new int[N];
	int* length = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin>>arr[i];
	}
	length[0] = 1;
	for (int i = 1; i < N; i++)
	{
		int maxLength = 0;
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[i] && length[j] > maxLength)
			{
				maxLength = length[j];
			}
		}
		length[i] = maxLength + 1;
	}
	int finalMaxLength = 0;
	for (int i = 0; i < N; i++)
	{
		if (length[i] > finalMaxLength)
		{
			finalMaxLength = length[i];
		}
	}
	cout << finalMaxLength << "\n";
	return 0;
}