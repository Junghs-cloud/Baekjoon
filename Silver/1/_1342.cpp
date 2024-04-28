#include <iostream>
#include <algorithm>
using namespace std;
string str;
int N;
int* alphabets;
int answer = 0;

void backTracking(int depth, int prev)
{
	if (depth == N)
	{
		answer++;
	}
	else
	{
		for (int i = 0; i < 26; i++)
		{
			if (alphabets[i] != 0)
			{
				if (depth == 0)
				{
					alphabets[i]--;
					backTracking(depth + 1, i);
					alphabets[i]++;
				}
				else
				{
					if (i != prev)
					{
						alphabets[i]--;
						backTracking(depth + 1, i);
						alphabets[i]++;
					}
				}
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> str;
	N = str.length();
	alphabets = new int[26];
	for (int i = 0; i < 26; i++)
	{
		alphabets[i] = 0;
	}
	for (int i = 0; i < N; i++)
	{
		int index = str.at(i) - 97;
		alphabets[index]++;
	}
	backTracking(0, -1);
	cout << answer << "\n";
	return 0;
}