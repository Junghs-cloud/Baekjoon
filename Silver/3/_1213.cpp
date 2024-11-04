#include <iostream>
#include <queue>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	cin >> str;
	int N = str.length();
	int* counts = new int[26];
	queue<pair<char, int>> even;
	queue<pair<char, int>> odd;
	string answer = "";
	for (int i = 0; i < 26; i++)
	{
		counts[i] = 0;
	}
	for (int i = 0; i < N; i++)
	{
		int index = str.at(i) - 65;
		counts[index]++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (counts[i] % 2 == 0 && counts[i] != 0)
		{
			even.push(pair('A' + i, counts[i]));
		}
		else if (counts[i] % 2 != 0)
		{
			odd.push(pair('A' + i, counts[i]));
		}
	}
	if (N % 2 == 0)
	{
		if (odd.size() != 0)
		{
			cout << "I'm Sorry Hansoo" << "\n";
		}
		else
		{
			while (!even.empty())
			{
				pair<char, int> current = even.front();
				answer.append(current.second / 2, current.first);
				even.pop();
			}
			string tailParts = answer.substr();
			reverse(tailParts.begin(), tailParts.end());
			answer += tailParts;
			cout << answer << "\n";
		}
	}
	else
	{
		if (odd.size() != 1)
		{
			cout << "I'm Sorry Hansoo" << "\n";
		}
		else
		{
			char oddChar = 'A';
			while (!even.empty())
			{
				pair<char, int> current = even.front();
				if (!odd.empty() && odd.front() < current)
				{
					answer.append(odd.front().second / 2, odd.front().first);
					oddChar = odd.front().first;
					odd.pop();
				}
				else
				{
					answer.append(current.second / 2, current.first);
					even.pop();
				}
			}
			if (!odd.empty())
			{
				answer.append(odd.front().second / 2, odd.front().first);
				oddChar = odd.front().first;
				odd.pop();
			}
			string tailParts = answer.substr();
			reverse(tailParts.begin(), tailParts.end());
			answer += oddChar;
			answer += tailParts;
			cout << answer << "\n";
		}
	}
	return 0;
}