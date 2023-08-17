#include <iostream>
#include <algorithm>
using namespace std;
char* arr;
char* answer;
bool* isVisited;
int strLength;
string str;

void backTracking(int depth)
{
	char prev = '\0';
	if (depth == strLength)
	{
		for (int i = 0; i < strLength; i++)
		{
			cout << answer[i];
		}
		cout << "\n";
	}
	else
	{
		for (int i = 0; i < strLength; i++)
		{
			if (isVisited[i] == false && arr[i] != prev)
			{
				answer[depth] = arr[i];
				isVisited[i] = true;
				prev = arr[i];
				backTracking(depth + 1);
				isVisited[i] = false;
			}

		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> str;
		strLength = (signed) str.length();
		arr = new char[str.length()];
		answer = new char[str.length()];
		isVisited = new bool[str.length()];
		for (int j = 0; j < str.length(); j++)
		{
			isVisited[j] = false;
			arr[j] = str[j];
		}
		sort(arr, arr+strLength);
		backTracking(0);
	}
	return 0;
}