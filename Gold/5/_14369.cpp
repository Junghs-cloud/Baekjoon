#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
char* strings;
bool* isChecked;
int strLength;

bool checkDist(char c)
{
	for (int i = 0; i < strLength; i++)
	{
		if (strings[i] == c && isChecked[i]==false)
		{
			isChecked[i] = true;
			return true;
		}
	}
	return false;
}

void erase(char c)
{
	for (int i = 0; i < strLength; i++)
	{
		if (strings[i] == c && isChecked[i] == false)
		{
			isChecked[i] = true;
			break;
		}
	}
}

int main()
{
	int N;
	string str;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		strings = new char[str.size()];
		isChecked = new bool[str.size()];
		strLength = (signed) str.size();

		int currentLength = strLength;
		bool firstErase = false;
		bool secondErase = false;
		bool thirdErase = false;
		vector<int> v;
		for (int j = 0; j < str.size(); j++)
		{
			strings[j] = str.at(j);
			isChecked[j] = false;
		}

		while (firstErase == false)
		{
			//zero
			if (checkDist('Z'))
			{
				v.push_back(0);
				erase('E');
				erase('R');
				erase('O');
			}
			//two
			else 	if (checkDist('W'))
			{
				v.push_back(2);
				erase('T');
				erase('O');
			}
				//four
			else if (checkDist('U'))
			{
				v.push_back(4);
				erase('F');
				erase('O');
				erase('R');
			}
				//six
			else if (checkDist('X'))
			{
				v.push_back(6);
				erase('S');
				erase('I');
			}
			else if (checkDist('G'))
			{
				v.push_back(8);
				erase('E');
				erase('I');
				erase('H');
				erase('T');
			}
			else
			{
				firstErase = true;
			}
		}
		while (secondErase == false)
		{
			//one
			if (checkDist('O'))
			{
				v.push_back(1);
				erase('N');
				erase('E');
			}
			//three
			else if (checkDist('T'))
			{
				v.push_back(3);
				erase('H');
				erase('R');
				erase('E');
				erase('E');
			}
			else
			{
				secondErase = true;
			}
		}
		while (thirdErase == false)
		{
			//five
			if (checkDist('F'))
			{
				v.push_back(5);
				erase('I');
				erase('V');
				erase('E');
			}
				//seven
			else if (checkDist('S'))
			{
				v.push_back(7);
				erase('E');
				erase('V');
				erase('E');
				erase('N');
			}
				//nine
			else if (checkDist('N'))
			{
				v.push_back(9);
				erase('I');
				erase('N');
				erase('E');
			}
			else
			{
				thirdErase = true;
			}
		}
		sort(v.begin(), v.end());
		cout << "Case #" << i + 1 << ": ";
		for (int i = 0; i < v.size(); i++)
		{
			cout << v.at(i) << "";
		}
		cout << "\n";
	}
	return 0;
}