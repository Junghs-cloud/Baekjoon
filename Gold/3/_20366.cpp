#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* arr = new int[N];
	int start, end;
	int answer = 2000000000;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	for (int i = 0; i <= N - 4; i++)
	{
		for (int j = i + 3; j < N; j++)
		{
			start = i + 1;
			end = j - 1;
			int firstSnowman = arr[i] + arr[j];
			while (start < end)
			{
				int secondSnowman = arr[start] + arr[end];
				int diff = firstSnowman - secondSnowman;
				if (diff < 0)
				{
					end--;
				}
				else
				{
					start++;
				}
				answer = min(answer, abs(diff));
			}
		}
	}
	std::cout << answer << "\n";
	return 0;
}