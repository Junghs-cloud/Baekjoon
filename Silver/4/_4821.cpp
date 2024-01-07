#include <iostream>
#include <sstream>
#include <string>
using namespace std;
bool* book;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	while (true)
	{
		int pages;
		int answer = 0;
		cin >> pages;
		if (pages == 0)
		{
			break;
		}
		else
		{
			book = new bool[pages + 1];
			for (int i = 0; i < pages + 1; i++)
			{
				book[i] = false;
			}
			string str, token;
			cin >> str;
			istringstream ss(str);
			
			while (getline(ss, token, ','))
			{
				if (token.find('-') == string::npos)
				{
					int stringToNum = stoi(token);
					if (stringToNum < pages + 1)
					{
						book[stringToNum] = true;
					}
				}
				else
				{
					int index = token.find('-');
					string lowStr = token.substr(0, index);
					string highStr = token.substr(index + 1);
					int low = stoi(lowStr);
					int high = stoi(highStr);
					if (low < pages + 1)
					{
						for (int i = low; (i <= high && i < pages + 1); i++)
						{
							book[i] = true;
						}
					}
				}
			}
			for (int i = 0; i < pages + 1; i++)
			{
				if (book[i] == true)
				{
					answer++;
				}
			}
			cout << answer << "\n";
			ss.str("");
		}
	}
	return 0;
}