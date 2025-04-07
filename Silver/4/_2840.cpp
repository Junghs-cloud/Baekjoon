#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K, S;
	char c;
	cin >> N >> K;
	char* arr = new char[N];
	int* indexes = new int[26];
	int currentPos = 0;
	bool canMake = true;
	for (int i = 0; i < N; i++)
	{
		arr[i] = '?';
	}
	for (int i = 0; i < 26; i++)
	{
		indexes[i] = -1;
	}
	for (int i = 0; i < K; i++)
	{
		cin >> S >> c;
		currentPos += S;
		currentPos %= N;
		int index = c - 'A';
		if (arr[currentPos] == '?' && (indexes[index] == currentPos || indexes[index]==-1))
		{
			arr[currentPos] = c;
			indexes[index] = currentPos;
		}
		else if (arr[currentPos] == c)
		{
			continue;
		}
		else
		{
			canMake = false;
		}
	}
	if (canMake == true)
	{
		for (int i = 0; i < N; i++)
		{
			cout << arr[currentPos];
			currentPos--;
			if (currentPos == -1)
			{
				currentPos = N - 1;
			}
		}
	}
	else
	{
		cout << "!" << "\n";
	}
	return 0;
}