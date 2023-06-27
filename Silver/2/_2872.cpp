#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	int changeCount = 0;
	int bookNum = 0;
	bool isMax = false;
	vector<int> books;
	cin >> N;
	int nextNum = N;
	for (int i = 1; i <= N; i++)
	{
		cin >> bookNum;
		books.push_back(bookNum);
	}
	for (int i = N - 1; i >= 0; i--)
	{
		if (books.at(i) == N)
		{
			isMax = true;
		}
		if (isMax == true)
		{
			if (books.at(i) == nextNum)
			{
				nextNum--;
			}
			else
			{
				changeCount++;
			}
		}
		else
		{
			changeCount++;
		}
	}
	cout << changeCount << "\n";
	return 0;
}