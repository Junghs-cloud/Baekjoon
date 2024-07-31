#include <iostream>
#include <algorithm>
using namespace std;

int* index;
bool* isVisited;
string* str;
int N;
int answer = 100000;
int middles = 0;

void backTracking(int depth, int currentCount)
{
	if (depth == N)
	{
		answer = min(answer, currentCount);
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			if (isVisited[i] == false)
			{
				index[depth] = i;
				isVisited[i] = true;
				if (depth == 0)
				{
					backTracking(depth + 1, currentCount);
				}
				else
				{
					string prevString = str[index[depth - 1]];
					int length = prevString.length();
					if (prevString[length - 1] != str[index[depth]].at(0))
					{
						backTracking(depth + 1, currentCount+1);
					}
					else
					{
						backTracking(depth + 1, currentCount);
					}
				}
				isVisited[i] = false;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	index = new int[N];
	str = new string[N];
	isVisited = new bool[N];
	for (int i = 0; i < N; i++)
	{
		isVisited[i] = false;
		cin >> str[i];
		for (int j = 1; j < str[i].length(); j++)
		{
			if (str[i].at(j) != str[i].at(j - 1))
			{
				middles++;
			}
		}
	}
	backTracking(0, middles);
	cout << answer << "\n";
	return 0;
}