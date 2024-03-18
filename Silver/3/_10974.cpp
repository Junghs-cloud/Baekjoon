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
		arr[i] = i + 1;
	}
	do
	{
		for (int i = 0; i < N; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
	} while (next_permutation(arr, arr + N));
	return 0;
}