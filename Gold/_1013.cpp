#include <iostream>
#include <string>
using namespace std;
string str;

void erase1001()
{

}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		int index1 = 0;
		int index2 = 0;
		bool isCorrect = true;
		while (str != "\0")
		{
			if (str.find("100") != string::npos)
			{
				index1 = str.find("100");
			}
			else
			{
				index1 = -1;
			}
			if (str.find("01") != string::npos)
			{
				index2 = str.find("01");
			}
			else
			{
				index2 = -1;
			}
			if (index2 == 0)
			{
				str = str.substr(index2 + 2);
			}
			else if (index1 == 0)
			{
				str = str.substr(index1 + 3);
				while (str != "\0")
				{
					if (str.find("0") != string::npos)
					{
						int index = str.find("0");
						if (index == 0)
						{
							str = str.substr(1);
						}
						else
						{
							break;
						}
					}
					else
					{
						break;
					}
				}
				if (str[0] == '1')
				{
					str = str.substr(1);
					while (str != "\0")
					{
						if (str[0] == '0')
						{
							break;
						}
						if (str.find("100") != string::npos)
						{
							int index = str.find("100");
							if (index == 0)
							{
								break;
							}
							else if (index != 0 && str[0] == '1')
							{
								str = str.substr(1);
							}
						}
						else
						{
							str = str.substr(1);
						}
					}
				}
				else
				{
					isCorrect = false;
					break;
				}
			}
			else
			{
				isCorrect = false;
				break;
			}
		}
		if (isCorrect == true)
		{
			cout << "YES" << "\n";
		}
		else
		{
			cout << "NO" << "\n";
		}
	}
	return 0;
}