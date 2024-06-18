#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	int start = 0;
	int end = N - 1;
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			start = i;
			end = N - 1;
			while (start <= end)
			{
				cout << i << " " << j <<" " << start <<" " << end << "\n";
				if (arr[i] + arr[j] + arr[start] < arr[end])
				{
					end--;
				}
				else if (arr[i] + arr[j] + arr[start] > arr[end])
				{
					start++;
				}
				else
				{
					answer = max(answer, arr[end]);
				}
			}

		}
	}
	cout << answer << "\n";
	return 0;
}