#include <iostream>
#include <map>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	string bookName;
	map<string, int> m;
	map<string, int>:: iterator it;
	int maxBookCount = 0;
	string maxBookName="";
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> bookName;
		it = m.find(bookName);
		if (it == m.end())
		{
			m.insert({bookName, 1});
		}
		else
		{
			it->second++;
		}
	}
	for (it = m.begin(); it != m.end(); it++)
	{
		if (it->second > maxBookCount)
		{
			maxBookCount = it->second;
			maxBookName = it->first;
		}
	}
	cout << maxBookName<<"\n";
	return 0;
}