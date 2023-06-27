#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	string str;
	cin >> N >> M;
	map<string, int> listen;
	map<string, int> see;
	map<string, int> listenSee;
	map<string, int>::iterator it;
	map<string, int>:: iterator iter;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		listen.insert({ str, 1 });
	}
	for (int j = 0; j < M; j++)
	{
		cin >> str;
		see.insert({ str, 1 });
	}
	for (iter = listen.begin(); iter != listen.end(); iter++)
	{
		it = see.find(iter->first);
		if (it != see.end())
		{
			listenSee.insert({ iter->first, 1 });
		}
	}
	cout << listenSee.size()<<"\n";
	for (iter = listenSee.begin(); iter != listenSee.end(); iter++)
	{
		cout << iter->first << "\n";
	}
	return 0;
}