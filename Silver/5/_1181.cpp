#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string &str1, string &str2)
{
	if (str1.length() < str2.length())
	{
		return true;
	}
	else if (str1.length() == str2.length())
	{
		if (str1 < str2)
		{
			return true;
		}
		else
		{
			return false;
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

	int N;
	string str;
	string prev, current;
	vector<string> words;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		words.push_back(str);
	}
	sort(words.begin(), words.end(), compare);
	cout << words.at(0)<<"\n";
	for (int i = 1; i < (signed) words.size(); i++)
	{
		prev = words.at(i - 1);
		current = words.at(i);
		if (current != prev)
		{
			cout << current << "\n";
		}

	}
	return 0;
}