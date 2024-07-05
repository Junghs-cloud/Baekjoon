#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	set<char> s;
	string* arr = new string[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < 26; i++)
	{
		int count = 0;
		for (int j = 0; j < N; j++)
		{
			if (arr[j][0] == 65+i)
			{
				count++;
			}
		}
		char c = 65 + i;
		if (count > 1)
		{
			for (int j = 0; j < N; j++)
			{
				s.insert(max(c, arr[j][1]));
			}
		}
		else if (count == 1)
		{
			for (int j = 0; j < N; j++)
			{
				if (arr[j][0] == c)
				{
					continue;
				}
				s.insert(max(c, arr[j][1]));
			}
		}
	}
	cout << s.size() << "\n";
	for (set<char>::iterator it=s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	return 0;
}