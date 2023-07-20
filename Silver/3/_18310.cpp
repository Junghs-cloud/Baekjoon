#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* arr = new int[N];
	long long max = 0;
	int left = 0;
	int right = N;
	long long prev = max;
	long long current;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		max += arr[i];
	}
	sort(arr, arr + N);
	if (N == 1)
	{
		cout << arr[0] << "\n";
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			current = prev + left - right;
			if (current >= prev)
			{
				cout << arr[i - 1] << "\n";
				break;
			}
			left++;
			right--;
			prev = current;
		}
	}
	return 0;
}