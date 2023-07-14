#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	string* arr = new string[N];
	int strLengthSum = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		strLengthSum += arr[i].length();
	}
	if (strLengthSum == M)
	{
		for (int i = 0; i < N; i++)
		{
			cout << arr[i];
		}
	}
	else
	{
		if ((M - strLengthSum) % (N - 1) == 0)
		{
			int _count = (M - strLengthSum) / (N - 1);
			for (int i = 0; i < N-1; i++)
			{
				cout << arr[i];
				for (int j = 0; j < _count; j++)
				{
					cout << "_";
				}
			}
			cout << arr[N - 1];
		}
		else
		{
			int _count = (M - strLengthSum) / (N - 1);
			int _lessCount = ((M - strLengthSum) / (N - 1)) * (N-1);
			int _moreCount = (M-strLengthSum) - _lessCount;
			_lessCount = N- 1 - _moreCount;
			for (int i = 0; i < N - 1; i++)
			{
				cout << arr[i];
				if (_lessCount == 0)
				{
					for (int j = 0; j < _count + 1; j++)
					{
						cout << "_";
					}
				}
				else if (_moreCount == 0)
				{
					for (int j = 0; j < _count; j++)
					{
						cout << "_";
					}
				}
				else
				{
					if (arr[i + 1].at(0) >= 97)
					{
						_moreCount--;
						for (int j = 0; j < _count + 1; j++)
						{
							cout << "_";
						}
					}
					else
					{
						_lessCount--;
						for (int j = 0; j < _count; j++)
						{
							cout << "_";

						}
					}
				}

			}
			cout << arr[N - 1];
		}
	}
	return 0;
}