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
	int up = 0;
	int down = 0;
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i < N; i++)
	{
		if (arr[i - 1] < arr[i])
		{
			up++;
			down = 0;
			answer = max(answer, up);
		}
		else if (arr[i - 1] == arr[i])
		{
			continue;
		}
		else
		{
			down++;
			up = 0;
			answer = max(down, answer);
		}
	}
	cout << answer + 1 << "\n";
	return 0;
}