#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	string pattern, str;
	cin >> N;
	cin >> pattern;
	int index = pattern.find("*");
	string front = pattern.substr(0, index);
	string back = pattern.substr(index + 1);
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		if (str.length() < front.length() + back.length())
		{
			cout << "NE" << "\n";
		}
		else
		{
			bool frontCheck = true;
			bool backCheck = true;
			int index = back.length() - 1;
			for (int j = 0; j < front.length(); j++)
			{
				if (str.at(j) != front.at(j))
				{
					frontCheck = false;
					break;
				}
			}
			for (int j = str.length() - 1; j >= str.length() - back.length(); j--)
			{
				if (str.at(j) != back.at(index) || j < front.length())
				{
					backCheck = false;
					break;
				}
				index--;
			}
			if (frontCheck == true && backCheck == true)
			{
				cout << "DA" << "\n";
			}
			else
			{
				cout << "NE" << "\n";
			}
		}

	}
	return 0;
}