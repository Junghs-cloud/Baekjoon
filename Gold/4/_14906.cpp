#include <iostream>
using namespace std;

bool checkSlump(string str)
{
	if (str[0] != 'D' && str[0] != 'E')
	{
		return false;
	}
	else
	{
		for (int i = 1; i < str.length(); i++)
		{
			if (i == str.length() - 1 && str[i] == 'G')
			{
				return true;
			}
			else if (i == str.length() - 1 && str[i] != 'G')
			{
				return false;
			}
			else
			{
				if (str[i] == 'F')
				{
					continue;
				}
				else if (str[i] == 'D' || str[i] == 'E')
				{
					if (checkSlump(str.substr(i)) == true)
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
		}
	}
}

bool checkSlimp(string str)
{
	if (str[0] != 'A')
	{
		return false;
	}
	else
	{
		if (str[1] == 'H')
		{
			return true;
		}
		else if (str[1] == 'B')
		{
			int subStrLength = str.length() - 3;
			if (checkSlimp(str.substr(2, subStrLength)) == true)
			{
				if (str[str.length() - 1] == 'C')
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
		else if (str[1] == 'D' || str[1] == 'E')
		{
			int subStrLength = str.length() - 2;
			if (checkSlump(str.substr(1, subStrLength)) == true)
			{
				if (str[str.length() - 1] == 'C')
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
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	cout << "SLURPYS OUTPUT" << "\n";
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		bool isSlupy = true;
		if (str.length() < 2)
		{
			isSlupy = false;
			continue;
		}
		else
		{
			if (str[0] != 'A')
			{
				isSlupy = false;
			}
			else
			{
				if (str[1] == 'H')
				{
					if (checkSlump(str.substr(2)) == true)
					{
						isSlupy = true;
					}
					else
					{
						isSlupy = false;
					}

				}
				else
				{
					if (str[1] == 'B')
					{
						if (str.find('D') != string::npos)
						{
							int index = (signed)str.find('D');
							if (checkSlimp(str.substr(0, index)) == true && checkSlump(str.substr(index)) == true)
							{
								isSlupy = true;
							}
							else
							{
								isSlupy = false;
							}
						}
						else if (str.find('E') != string::npos)
						{
							int index = (signed)str.find('E');
							if (checkSlimp(str.substr(0, index)) == true && checkSlump(str.substr(index)) == true)
							{
								isSlupy = true;
							}
							else
							{
								isSlupy = false;
							}
						}
						else
						{
							isSlupy = false;
						}
					}
					else if (str[1] == 'D' ||  str[1] == 'E')
					{
						if (str.find('C') != string::npos)
						{
							int index= (signed)str.find('C');
							if (checkSlimp(str.substr(0, index + 1)) == true && checkSlump(str.substr(index + 1)) == true)
							{
								isSlupy = true;
							}
							else
							{
								isSlupy = false;
							}
						}
						else
						{
							isSlupy = false;
						}
					}
					else
					{
						isSlupy = false;
					}
				}
			}
			if (isSlupy == true)
			{
				cout << "YES" << "\n";
			}
			else
			{
				cout << "NO" << "\n";
			}
		}
	}
	cout << "END OF OUTPUT" << "\n";
	return 0;
}