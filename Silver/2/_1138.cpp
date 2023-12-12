#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* arr= new int[N];
	int* answer = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin>>arr[i];
		answer[i] = 11;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = arr[i]; j < N; j++)
		{
			if (answer[j] == 11)
			{
				int bigger = 0;
				for (int k = 0; k < j; k++)
				{
					if (answer[k] > i + 1)
					{
						bigger++;
					}
				}
				if (bigger == arr[i])
				{
					answer[j] = i + 1;
					break;
				}
				else
				{
					continue;
				}
			}
			else
			{
				continue;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		cout << answer[i] << " ";
	}
	return 0;
}