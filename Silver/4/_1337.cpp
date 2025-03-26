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
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	int start = 0;
	int end = 0;
	int maxLength = 0;
	while (start < N)
	{
		while (true)
		{
			end++;
			if (end >= N || arr[end] - arr[start] > 4)
			{
				break;
			}
		}
		end--;
		maxLength = max(maxLength, end - start + 1);
		start++;
	}
	cout << 5 - maxLength << "\n";
	return 0;
}