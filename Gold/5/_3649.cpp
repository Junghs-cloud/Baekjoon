#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	while (true)
	{
		int X, N;
		cin >> X;
		if (cin.eof())
		{
			break;
		}
		cin >> N;
		int* arr = new int[N];
		for (int i = 0; i < N; i++)
		{
			cin >> arr[i];
		}
		sort(arr, arr + N);
		long long length = 10000000 * X;
		bool canMake = false;
		for (int i = 0; i < N; i++)
		{
			if (binary_search(arr + i + 1, arr + N, length - arr[i]) == true)
			{
				cout << "yes " << arr[i] << " " << length - arr[i] << "\n";
				canMake = true;
				break;
			}
		}
		if (canMake == false)
		{
			cout << "danger" << "\n";
		}
	}

	return 0;
}