#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* arr = new int[N];
	int w, h;
	long long answer = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i < N; i++)
	{
		w = arr[i] + arr[i - 1];
		h = abs(arr[i] - arr[i - 1]);
		answer += (w * w) + (h * h);
	}
	cout << answer << "\n";
	return 0;
}