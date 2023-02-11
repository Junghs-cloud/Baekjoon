#include <iostream>
#include <vector>
using namespace std;
vector<int> shouldPrintPages;
int ink = 0;

void printPages()
{
	while (!shouldPrintPages.empty())
	{
		int current = shouldPrintPages.at(0);
		int prevLength = 0;
		int vectorPageCount = 0;
		for (int i = 0; i < (signed) shouldPrintPages.size(); i++)
		{
			int length = shouldPrintPages.at(i) - current + 1;
			int currentInk = 5 + 2 * length;
			int unContinueInk;
			if (i == 0)
			{
				unContinueInk = 14;
			}
			else
			{
				unContinueInk = 5 + 2 * prevLength + 7;
			}
			if (currentInk < unContinueInk)
			{
				if (i == shouldPrintPages.size() - 1)
				{
					ink += 5 + 2 * length;
					while (!shouldPrintPages.empty())
					{
						shouldPrintPages.erase(shouldPrintPages.begin());
					}
					break;
				}
				prevLength = length;
				vectorPageCount++;

			}
			else
			{
				ink += 5 + 2 * prevLength;
				for (int j = 0; j < vectorPageCount; j++)
				{
					shouldPrintPages.erase(shouldPrintPages.begin());
				}
				break;
			}
		}

	}
	cout << ink << "\n";
}

int main()
{
	int page;
	int N, M;
	bool* isExistence;
	cin >> N >> M;

	isExistence = new bool[N];
	for (int i = 0; i < N; i++)
	{
		isExistence[i] = false;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> page;
		isExistence[page - 1] = true;
	}
	
	for (int i = 0; i < N; i++)
	{
		if (isExistence[i] == false)
		{
			shouldPrintPages.push_back(i+1);
		}
	}
	printPages();
	return 0;
}