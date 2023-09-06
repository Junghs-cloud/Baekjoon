#include <iostream>
#include <algorithm>
using namespace std;
string* str;
int answer = 0;
void binarySearch(string findStr,  int left, int right)
{
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (findStr < str[middle])
		{
			right = middle - 1;
		}
		else if (findStr > str[middle])
		{
			left = middle + 1;
		}
		else
		{
			answer++;
			break;
		}
		if (str[middle].find(findStr) != string::npos)
		{
			int index = str[middle].find(findStr);
			if (index == 0)
			{
				answer++;
				break;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	str = new string[N];
	string findStr;
	for (int i = 0; i < N; i++)
	{
		cin >> str[i];
	}
	sort(str, str + N);
	for (int i = 0; i < M; i++)
	{
		cin >> findStr;
		binarySearch(findStr, 0, N-1 );
	}
	cout << answer << "\n";
	return 0;
}