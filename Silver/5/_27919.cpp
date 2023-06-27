#include <iostream>
using namespace std;

int main()
{
	string str;
	int vote[4];
	bool C = true;
	for (int i = 0; i < 4; i++)
	{
		vote[i] = 0;
	}
	cin >> str;
	for (int i = 0; i < (signed)str.length(); i++)
	{
		if (str[i] == 'U')
		{
			vote[0]++;
		}
		else if (str[i] == 'D')
		{
			vote[1]++;
		}
		else if (str[i] == 'P')
		{
			vote[2]++;
		}
		else
		{
			vote[3]++;
		}
	}
	int allU = vote[0] + vote[3];
	int allD = vote[1] + vote[2];
	for (int i = 0; i <= allD; i++)
	{
		int a = i;
		int b = allD - a;
		if (allU > a && allU > b)
		{
			cout << "U";
			C = false;
			break;
		}
	}
	for (int i = 0; i <= allU; i++)
	{
		int a = i;
		int b = allU - a;
		if (allD > a)
		{
			cout << "DP";
			C = false;
			break;
		}
	}
	if (C == true)
	{
		cout << "C";
	}
	cout << "\n";
	return 0;
}