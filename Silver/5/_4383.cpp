#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	while (true)
	{
		int N;
		cin >> N;
		if (cin.eof() == true)
		{
			break;
		}
		bool* abss = new bool[N];
		int* arr = new int[N];
		int count = 0;
		for (int i = 0; i < N; i++)
		{
			abss[i] = false;
		}
		for (int i = 0; i < N; i++)
		{
			cin >> arr[i];
		}
		for (int i = 1; i < N; i++)
		{
			int dx = abs(arr[i] - arr[i - 1]);
			abss[dx] = true;
		}
		for (int i = 1; i < N; i++)
		{
			if (abss[i] == true)
			{
				count++;
			}
		}
		if (count == N - 1)
		{
			cout << "Jolly" << "\n";
		}
		else
		{
			cout << "Not jolly" << "\n";
		}
	}
	return 0;
}