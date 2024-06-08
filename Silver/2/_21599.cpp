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
	int answer = 0;
	int index = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N, greater<int>());
	for (int i=0;i<N;i++)
	{
		if (arr[i] == 0)
		{
			break;
		}
		answer = max(answer, i + arr[i]);
	}
	cout << min(answer, N) << "\n";
	return 0;
}