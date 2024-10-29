#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

set<string> s;
set<string>::iterator it1;
set<string>::iterator it2;

bool cmp(string s1, string s2)
{
	int index1 = s1.find('.');
	int index2 = s2.find('.');
	string fileName1 = s1.substr(0, index1);
	string fileName2 = s2.substr(0, index2);
	if (fileName1 < fileName2)
	{
		return true;
	}
	else if (fileName1 == fileName2)
	{
		string s1Ext = s1.substr(index1 + 1);
		string s2Ext = s2.substr(index2 + 1);
		it1 = s.find(s1Ext);
		it2 = s.find(s2Ext);
		if (it1 != s.end() && it2 == s.end())
		{
			return true;
		}
		else if (it1 == s.end() && it2 != s.end())
		{
			return false;
		}
		else
		{
			return s1Ext < s2Ext;
		}
	}
	else
	{
		return false;
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	string ext;
	cin >> N >> M;
	string* arr = new string[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < M; i++)
	{
		cin >> ext;
		s.insert(ext);
	}
	sort(arr, arr + N, cmp);
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << "\n";
	}
	return 0;
}