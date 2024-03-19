#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* arr = new int[N + 1];
	arr[0] = 0;
	for (int i = 1; i < N+1; i++)
	{
		arr[i] = i;
		for (int j = 1; j <= sqrt(i); j++)
		{
			arr[i] = min(arr[i], arr[i-(j * j)] + 1);
		}
	}
	cout << arr[N] << "\n";
	return 0;
}