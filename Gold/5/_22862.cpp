#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int S, K;
	cin >> S >> K;
	int* arr = new int[S];
	int currentOddNum = 0;
	int start = 0;
	int end = 0;
	int length = 0;
	for (int i = 0; i < S; i++)
	{
		cin >> arr[i];
	}
	while (start < S)
	{
		if (end < S - 1)
		{
			if (arr[end] % 2 != 0)
			{
				currentOddNum++;
			}
			while (currentOddNum > K)
			{
				if (start > end)
				{
					break;
				}
				else
				{
					if (arr[start] % 2 != 0)
					{
						currentOddNum--;
					}
					start++;
				}
			}
			length = max(length, end - start + 1-currentOddNum);
			end++;
		}
		else
		{
			if (arr[end] % 2 != 0)
			{
				currentOddNum++;
			}
			if (currentOddNum <= K)
			{
				length = max(length, end - start + 1 - currentOddNum);
				break;
			}
			while (currentOddNum > K)
			{
				if (start > end)
				{
					break;
				}
				else
				{
					if (arr[start] % 2 != 0)
					{
						currentOddNum--;
					}
					start++;
				}
			}
			length = max(length, end - start + 1-currentOddNum);
		}
	}
	cout << length << "\n";
	return 0;
}