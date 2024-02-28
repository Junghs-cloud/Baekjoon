#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	cin >> str;
	int N = str.length();
	bool** isPalindrome = new bool*[N];
	int* length = new int[N];
	for (int i = 0; i < N; i++)
	{
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
	length[0] = 1;
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (str[i] == str[j])
			{
				if (i - j == 1)
				{
					isPalindrome[i][j] = true;
				}
				else
				{
					isPalindrome[i][j] = isPalindrome[i -  1][j + 1];
				}
			}
			else
			{
				isPalindrome[i][j] = false;
			}
		}
	}
	for (int i = 1; i < N; i++)
	{
		bool canFound = false;
		length[i] = 100000;
		for (int j = 0; j <= i; j++)
		{
			if (isPalindrome[i][j] == true)
			{
				if (j == 0)
				{
					length[i] = 1;
				}
				else
				{
					length[i] = min(length[i], length[j - 1] + 1);
				}
			}
		}
	}
	cout << length[N - 1] << "\n";
	return 0;
}