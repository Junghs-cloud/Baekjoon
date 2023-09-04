#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* input = new int[N];
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> input[i];
		arr[i] = input[i];
	}
	sort(arr, arr + N);
	if (equal(arr, arr + N, input))
	{
		cout << -1 << "\n";
	}
	else
	{
		prev_permutation(input, input + N);
		for (int i = 0; i < N; i++)
		{
			cout << input[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}