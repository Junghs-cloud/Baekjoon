#include <iostream>
#include <queue>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str, T;
	long long answer = 0;
	bool canNotMakeAnymore = false;
	queue<int>* alphabets = new queue<int>[26];
	cin >> str;
	cin >> T;
	int strLength = str.length();
	int tLength = T.length();
	for (int i = 0; i < strLength; i++)
	{
		int index = str[i] - 97;
		alphabets[index].push(i);
	}
	while (canNotMakeAnymore == false)
	{
		int currentIndex = -1;
		for (int i = 0; i < tLength; i++)
		{
			int currentNeedAlphabetIndex = T[i] - 97;
			if (alphabets[currentNeedAlphabetIndex].empty())
			{
				canNotMakeAnymore = true;
				break;
			}
			else
			{
				bool isAllocated = false;
				while (!alphabets[currentNeedAlphabetIndex].empty())
				{
					int front = alphabets[currentNeedAlphabetIndex].front();
					alphabets[currentNeedAlphabetIndex].pop();
					if (front > currentIndex)
					{
						isAllocated = true;
						currentIndex = front;
						break;
					}
				}
				if (isAllocated == false)
				{
					canNotMakeAnymore = true;
					break;
				}
			}
		}
		if (canNotMakeAnymore == true)
		{
			break;
		}
		else
		{
			answer++;
		}
	}
	cout << answer << "\n";
	return 0;
}