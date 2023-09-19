#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int M, K;

	cin >> N;
	cin >> M >> K;
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N, greater<int>());
	int pen = 0;
	bool b = false;
	for (int i = 0; i < N; i++)
	{
		pen += arr[i];
		if (pen >= M * K)
		{
			cout << i + 1 << "\n";
			b = true;
			break;
		}
	}
	if (b == false)
	{
		cout << "STRESS" << "\n";
	}
	return 0;
}