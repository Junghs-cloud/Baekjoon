#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(const string& str1, const string& str2)
{
	if (str1.length() < str2.length())
	{
		return true;
	}
	else if (str1.length() == str2.length())
	{
		int sum1 = 0;
		int sum2 = 0;
		for (int i = 0; i < str1.length(); i++)
		{
			if (str1[i] >= 48 && str1[i] <= 57)
			{
				sum1 += str1[i] - 48;
			}
			if (str2[i] >= 48 && str2[i] <= 57)
			{
				sum2 += str2[i] - 48;
			}
		}
		if (sum1 < sum2)
		{
			return true;
		}
		else if (sum1 == sum2)
		{
			if (str1.compare(str2) < 0)
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
	else
	{
		return false;
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	int N;
	cin >> N;
	vector<string> v;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		v.push_back(str);
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < N; i++)
	{
		cout << v.at(i) << "\n";
	}
	return 0;
}