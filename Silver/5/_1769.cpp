#include <iostream>
#include <string>
using namespace std;
int changeCount = 0;

void print(int num)
{
	cout << changeCount << "\n";
	if (num % 3 == 0)
	{
		cout << "YES" << "\n";
	}
	else
	{
		cout << "NO" << "\n";
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	cin >> str;
	if (str.length() == 1)
	{
		int num = str.at(0) - 48;
		print(num);
	}
	else
	{
		while (true)
		{
			changeCount++;
			int num = 0;
			for (int i = 0; i < str.length(); i++)
			{
				num += str.at(i) - 48;
			}
			str = to_string(num);
			if (str.length() == 1)
			{
				print(num);
				break;
			}
		}
	}
	return 0;
}