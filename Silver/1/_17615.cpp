#include <iostream>
#include <algorithm>
using namespace std;
int N;
string str;

int sendBack()
{
	int diffCount = 0;
	int sameCount = 0;
	int lastDiffIndex = 0;
	for (int i = N - 1; i >= 0; i--)
	{
		if (str[i] != str[N - 1])
		{
			lastDiffIndex = i;
			break;
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (str[i] != str[N - 1])
		{
			diffCount++;
		}
		else if (i < lastDiffIndex)
		{
			sameCount++;
		}
	}
	return min(diffCount, sameCount);
}

int sendFront()
{
	int diffCount = 0;
	int sameCount = 0;
	int firstDiffIndex = N-1;
	for (int i = 0; i < N; i++)
	{
		if (str[i] != str[0])
		{
			firstDiffIndex = i;
			break;
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (str[i] != str[0])
		{
			diffCount++;
		}
		else if (i > firstDiffIndex)
		{
			sameCount++;
		}
	}
	return min(diffCount, sameCount);
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	cin >> str;
	cout << min(sendBack(), sendFront()) << "\n";
	return 0;
}