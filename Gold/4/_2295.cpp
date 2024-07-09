#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* arr = new int[N];
	set<int> s;
	set<int>::iterator it;
	int maxK = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			it = s.find(arr[i] + arr[j]);
			if (it == s.end())
			{
				s.insert(arr[i]+arr[j]);
			}
		}
	}
	for (int x = 0; x < N; x++)
	{
		for (int k = N - 1; k >= x; k--)
		{
			it = s.find(arr[k] - arr[x]);
			if (it != s.end() && arr[k] > maxK)
			{
				maxK = arr[k];
				break;
			}
		}
	}
	cout << maxK << "\n";
	return 0;
}