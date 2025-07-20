#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string s, t;
	while (true)
	{
		cin >> s >> t;
		if (cin.eof() == true)
		{
			break;
		}
		int index = 0;
		bool canMake = false;
		for (int i = 0; i < t.length(); i++)
		{
			if (t.at(i) == s.at(index))
			{
				index++;
				if (index == s.length())
				{
					canMake = true;
					break;
				}
			}
		}
		if (canMake == true)
		{
			cout << "Yes" << "\n";
		}
		else
		{
			cout << "No" << "\n";
		}
	}
	return 0;
}