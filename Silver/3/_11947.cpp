#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

long long pow(int x)
{
	long long answer = 10;
	for (int i = 1; i < x; i++)
	{
		answer *= 10;
	}
	return answer;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		string str;
		cin >> str;
		long long N = stoi(str);
		int length = str.length();
		long long maxPoint = pow(length) / 2;
		if (N < maxPoint)
		{
			long long answer = (pow(length) - 1 - N) * N;
			cout << answer << "\n";
		}
		else
		{
			long long answer = maxPoint * (pow(length) - 1 - maxPoint);
			cout << answer << "\n";
		}
	}
	return 0;
}