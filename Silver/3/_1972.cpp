#include <iostream>
#include <set>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	set<string>::iterator it;
	while (true)
	{
		cin >> str;
		if (str == "*")
		{
			break;
		}
		int N = str.length();
		bool isSurprising = true;
		for (int j = 1; j <= N - 2; j++)
		{
			set<string> se;
			for (int i = 0; i < N - j; i++)
			{
				string s = "";
				s.append(1, str[i]);
				s.append(1, str[i + j]);
				it = se.find(s);
				if (it != se.end())
				{
					isSurprising = false;
					break;
				}
				else
				{
					se.insert(s);
				}
			}
		}
		if (isSurprising == true)
		{
			cout << str << " is surprising.\n";
		}
		else
		{
			cout << str << " is NOT surprising.\n";
		}
	}
	return 0;
}