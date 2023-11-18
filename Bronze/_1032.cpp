#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N;
	cin >> N;
	string* strs = new string[N];
	string answer = "\0";
	for (int i = 0; i < N; i++)
	{
		cin >> strs[i];
	}
	int length = strs[0].length();
	for (int j = 0; j < length; j++)
	{
		int index = strs[0].at(j);

		bool allSame = true;
		for (int i = 0; i < N; i++)
		{
			if (strs[i].at(j) != index)
			{
				allSame = false;
			}
		}
		if (allSame == true)
		{
			answer += strs[0].at(j);
		}
		else
		{
			answer += "?";
		}
	}
	cout << answer << "\n";
	return 0;
}