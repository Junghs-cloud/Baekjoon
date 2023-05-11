#include <iostream>
#include <map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	string* arr = new string[N];

	map<string, int>:: iterator it;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	int stringLength = arr[0].length();
	for (int i = 0; i <= stringLength; i++)
	{
		map<string, int> m;
		bool allDiff = true;
		for (int j = 0; j < N; j++)
		{
			string currentString = arr[j].substr(stringLength - i);
			it = m.find(currentString);
			if ( it == m.end())
			{
				m.insert({ currentString, i + 1 });
			}
			else
			{
				allDiff = false;
				break;
			}
		}
		if (allDiff == true)
		{
			cout << i<<"\n";
			break;
		}
	}
	return 0;
}