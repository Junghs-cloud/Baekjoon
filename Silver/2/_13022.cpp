#include <iostream>
using namespace std;
string str;
int currentPos = 0;

int find(char c)
{
	int count = 0;
	if (str[currentPos] != c)
	{
		return 0;
	}
	for (int i = currentPos; i <(signed) str.length(); i++)
	{
		if (str[i] == c)
		{
			count++;
			currentPos++;
			continue;
		}
		else
		{
			break;
		}
	}
	return count;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> str;
	int wCount = 0;
	int oCount = 0;
	int lCount = 0;
	int fCount = 0;
	bool isCorrect = false;
	while (currentPos < (signed) str.length())
	{
		wCount = find('w');
		oCount = find('o');
		lCount = find('l');
		fCount = find('f');
		if (wCount == oCount && wCount == lCount && wCount == fCount)
		{
			isCorrect = true;
		}
		else
		{
			isCorrect = false;
			break;
		}
	}
	if (isCorrect == true)
	{
		cout << "1" << "\n";
	}
	else
	{
		cout << "0" << "\n";
	}
	return 0;
}