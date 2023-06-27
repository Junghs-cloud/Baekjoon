#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	int findWordCount = 0;
	string str;
	string findStr;
	map<string, int> strings;
	map<string, int>::iterator it;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		strings.insert({str, 1});
	}
	for (int i = 0; i < M; i++)
	{
		cin >> findStr;
		it = strings.find(findStr);
		if (it != strings.end())
		{
			findWordCount++;
		}
	}
	cout << findWordCount<<"\n";
	return 0;
}