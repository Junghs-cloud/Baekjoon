#include <iostream>
#include <map>
#include <sstream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	string word;
	string blogKeywords;
	string token;
	map<string, bool> m;
	map<string, bool>::iterator it;
	cin >> N>> M;
	for (int i = 0; i < N; i++)
	{
		cin >> word;
		m.insert({ word, true });
	}
	int mapSize = m.size();
	for (int i = 0; i < M; i++)
	{
		cin >> blogKeywords;
		stringstream ss(blogKeywords);
		while (getline(ss, token, ','))
		{
			it = m.find(token);
			if (it != m.end() && it->second == true)
			{
				it->second = false;
				mapSize--;
			}
		}
		cout << mapSize << "\n";
	}
	return 0;
}