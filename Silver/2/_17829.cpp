#include <iostream>
#include <algorithm>
using namespace std;

int pooling(int** arr, int length)
{
	if (length == 1)
	{
		return arr[0][0];
	}
	else
	{
		int newLength = length / 2;
		int** newArr = new int*[length / 2];
		for (int i = 0; i < newLength; i++)
		{
			newArr[i] = new int[newLength];
		}
		for (int i = 0; i < length; i+=2)
		{
			for (int j = 0; j < length; j += 2)
			{
				int part[] = {arr[i][j], arr[i + 1][j], arr[i][j + 1], arr[i + 1][j + 1]};
				sort(part, part + 4);
				newArr[i / 2][j / 2] = part[2];
			}
		}
		return pooling(newArr, newLength);
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int** arr = new int*[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[N];
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout<<pooling(arr, N);
	return 0;
}