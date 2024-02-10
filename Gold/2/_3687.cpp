#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string compareBigger(string s1, string s2)
{
	if (s1.length() > s2.length())
	{
		return s1;
	}
	else if (s1.length() == s2.length())
	{
		if (s1 > s2)
		{
			return s1;
		}
		else
		{
			return s2;
		}
	}
	else
	{
		return s2;
	}
}

string compareSmaller(string s1, string s2)
{
	if (s1.length() < s2.length())
	{
		return s1;
	}
	else if (s1.length() == s2.length())
	{
		if (s1 < s2)
		{
			return s1;
		}
		else
		{
			return s2;
		}
	}
	else
	{
		return s2;
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T, N;
	cin >> T;
	string* biggest = new string[101];
	string* smallest = new string[101];
	vector<int>* v = new vector<int>[8];
	for (int i = 0; i < 101; i++)
	{
		biggest[i] = "";
		smallest[i] = "";
	}
	v[2].push_back(1);
	v[3].push_back(7);
	v[4].push_back(4);

	v[5].push_back(2);
	v[5].push_back(3);
	v[5].push_back(5);

	v[6].push_back(0);
	v[6].push_back(6);
	v[6].push_back(9);

	v[7].push_back(8);
	for (int i = 2; i <= 7; i++)
	{
		biggest[i] = to_string(v[i].back());
		if (i == 6)
		{
			smallest[i] = "6";
		}
		else
		{
			smallest[i] = to_string(v[i].front());
		}
	}
	for (int i = 2; i < 101; i++)
	{
		for (int j =2; j <= 7; j++)
		{
			if (i + j < 101)
			{
				if (biggest[i + j] == "")
				{
					biggest[i + j] = biggest[i] + to_string(v[j].back());
				}
				else
				{
					string currentNumStr = biggest[i] + to_string(v[j].back());
					biggest[i + j] = compareBigger(biggest[i+j], currentNumStr);
				}
				if (smallest[i + j] == "")
				{
					smallest[i + j] = smallest[i] + to_string(v[j].front());
				}
				else
				{
					string currentNumStr = smallest[i] + to_string(v[j].front());
					smallest[i + j] = compareSmaller(smallest[i+j], currentNumStr);
				}
			}
		}
	}
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		cout << smallest[N] <<" " << biggest[N] << "\n";
	}
	return 0;
}