#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, start, end;
	cin >> N;
	int* arr = new int[N];
	bool** isPalindrome = new bool*[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		isPalindrome[i] = new bool[N];
		for (int j = 0; j < N; j++)
		{
			if (i == j)
			{
				isPalindrome[i][j] = true;
			}
			else
			{
				isPalindrome[i][j] = false;
			}
		}
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] == arr[j])
			{
				if (j == i - 1)
				{
					isPalindrome[i][j] = true;
				}
				else
				{
					isPalindrome[i][j] = isPalindrome[i - 1][j + 1];
				}
			}
		}
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> start >> end;
		cout << isPalindrome[end - 1][start - 1]<<"\n";
	}
	return 0;
}