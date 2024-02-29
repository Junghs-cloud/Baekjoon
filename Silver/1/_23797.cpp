#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	cin >> str;
	int endWithP, endWithK;
	int answer = 1;
	if (str[0] == 'P')
	{
		endWithP = 1;
		endWithK = 0;
	}
	else
	{
		endWithP = 0;
		endWithK = 1;
	}
	for (int i = 1; i < str.length(); i++)
	{
		if (str[i] == 'K')
		{
			if (endWithP == 0)
			{
				endWithK++;
			}
			else
			{
				endWithP--;
				endWithK++;
			}
		}
		else
		{
			if (endWithK == 0)
			{
				endWithP++;
			}
			else
			{
				endWithK--;
				endWithP++;
			}
		}
		int frog = max(endWithK, endWithP);
		answer = max(answer, frog);
	}
	cout << answer << "\n";
	return 0;
}