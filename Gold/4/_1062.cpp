#include <iostream>
using namespace std;
int N, M;
string* words;
bool* isUsed;
int answer;

void backTracking(int depth, int index)
{
	if (depth == M-5)
	{
		int canMakeCount = 0;
		for (int i = 0; i < N; i++)
		{
			bool canMake = true;
			for (int j = 0; j < words[i].length(); j++)
			{
				int index = words[i].at(j) - 97;
				if (isUsed[index] == false)
				{
					canMake = false;
					break;
				}
			}
			if (canMake == true)
			{
				canMakeCount++;
			}
		}
		answer = max(answer, canMakeCount);
	}
	else
	{
		for (int i = index; i < 26; i++)
		{
			if (isUsed[i] == false)
			{
				isUsed[i] = true;
				backTracking(depth + 1, i+1);
				isUsed[i] = false;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	string str;
	words = new string[N];
	isUsed = new bool[26];
	for (int i = 0; i < 26; i++)
	{
		isUsed[i] = false;
	}
	isUsed[0] = true;
	isUsed[2] = true;
	isUsed[8] = true;
	isUsed[13] = true;
	isUsed[19] = true;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		int cutLength = str.length()-8;
		words[i] = str.substr(4, cutLength);
	}
	if (M < 5)
	{
		cout << 0 << "\n";
	}
	else
	{
		backTracking(0, 0);
		cout << answer << "\n";
	}
	return 0;
}