#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N, A, B;
	cin >> N>>A>>B;
	int* arr = new int[N + 1];
	arr[N] = 0;
	for (int i = N-1; i >= 0; i--)
	{
		arr[i] = arr[i + 1] + 1;
		if (i + A + 1 <= N)
		{
			arr[i] = min(arr[i], arr[i + A + 1] + 1);
		}
		if (i + B + 1 <= N)
		{
			arr[i] = min(arr[i], arr[i + B + 1] + 1);
		}
	}
	cout << arr[0] << "\n";
	return 0;
}