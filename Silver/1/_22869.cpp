#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;
	int* arr = new int[N];
	bool* canMove = new bool[N];
	int F;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		canMove[i] = false;
	}
	canMove[0] = true;
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (canMove[j] == true)
			{
				F = (i - j) * (1+ abs(arr[i] - arr[j]));
				if (F <= K)
				{
					canMove[i] = true;
					break;
				}
			}
		}
	}
	if (canMove[N - 1] == true)
	{
		cout << "YES"<<"\n";
	}
	else
	{
		cout << "NO" << "\n";
	}
	return 0;
}