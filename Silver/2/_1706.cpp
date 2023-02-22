#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string str;
	string subStr;
	vector<string> stringVector;
	int r, c;

	cin >> r >> c;
	char** arr = new char*[r];
	for (int i = 0; i < r; i++)
	{
		arr[i] = new char[c];
		cin >> str;
		for (int j = 0; j < c; j++)
		{
			arr[i][j] = str[j];
		}
	}
	for (int i = 0; i < r; i++)
	{
		int start = 0;
		int end = c;
		string s;
		for (int j = 0; j < c; j++)
		{
			s.append(1, arr[i][j]);
		}
		for (int j = 0; j < c; j++)
		{
			if (s[j] == '#')
			{
				end = j;
				if (end == start)
				{
					start = j + 1;
					end = c;
					continue;
				}
				else
				{
					int length = end - start;
					subStr = s.substr(start, length);
					if(subStr.length() != 1)
					{
						stringVector.push_back(subStr);
					}
					start = j + 1;
					end = c;
				}
				
			}
		}
		if (start != end)
		{
			int length = end - start;
			subStr = s.substr(start, length);
			if (subStr.length() != 1)
			{
				stringVector.push_back(subStr);
			}
		}
	}
	for (int i = 0; i < c; i++)
	{
		int start = 0;
		int end = r;
		string s;
		for (int j = 0; j < r; j++)
		{
			s.append(1, arr[j][i]);
		}
		for (int j = 0; j < r; j++)
		{
			if (s[j] == '#')
			{
				end = j;
				if (end == start)
				{
					start = j + 1;
					end = r;
					continue;
				}
				else
				{
					int length = end - start;
					subStr = s.substr(start, length);
					if (subStr.length() != 1)
					{
						stringVector.push_back(subStr);
					}
					start = j + 1;
					end = r;
				}

			}
		}
		if (start != end)
		{
			int length = end - start;
			subStr = s.substr(start, length);
			if (subStr.length() != 1)
			{
				stringVector.push_back(subStr);
			}
		}
	}
	sort(stringVector.begin(), stringVector.end());
	std::cout << stringVector.at(0) << "\n";
	return 0;
}