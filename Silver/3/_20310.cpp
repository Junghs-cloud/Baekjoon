#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	int zero = 0;
	int one = 0;
	int zeroCount = 0;
	int oneCount = 0;
	string answer = "\0";
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '0')
		{
			zero++;
		}
		else
		{
			one++;
		}
	}
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '0' && zeroCount < zero/2)
		{
			zeroCount++;
			answer += "0";
		}
		if (str[i] == '1' && oneCount < one / 2)
		{
			oneCount++;
		}
		else if (str[i]=='1')
		{
			answer += "1";
		}
	}
	cout << answer << "\n";
	return 0;
}