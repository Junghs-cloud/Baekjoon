#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int danceCount = 1;
	int N;
	string first, second;
	vector<string> v;
	vector<string>::iterator it1;
	vector<string>::iterator it2;
	cin >> N;
	v.push_back("ChongChong");
	for (int i = 0; i < N; i++)
	{
		cin >> first >> second;
		it1 = find(v.begin(), v.end(), first);
		it2 = find(v.begin(), v.end(), second);
		if (it1 != v.end() && it2 == v.end())
		{
			v.push_back(second);
			danceCount++;
		}
		else if (it1 == v.end() && it2 != v.end())
		{
			v.push_back(first);
			danceCount++;
		}
	}
	cout << danceCount << "\n";
	return 0;
}