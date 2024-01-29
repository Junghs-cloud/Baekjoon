#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	string str;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> str;
		int strLength = str.length();
		string sPrime = "\0";
		if (strLength % 3 == 0)
		{
			sPrime = str.substr(0, strLength/3);
		}
		else
		{
			sPrime = str.substr(0, (strLength / 3) + 1);
		}
		string revSPrime = sPrime;
		string tailSPrime = sPrime.substr(1);
		reverse(revSPrime.begin(), revSPrime.end());
		if (sPrime + revSPrime + sPrime == str)
		{
			cout << "1" << "\n";
		}
		else if (sPrime + revSPrime.substr(1) + sPrime == str)
		{
			cout << "1" << "\n";
		}
		else if (sPrime + revSPrime + tailSPrime == str)
		{
			cout << "1" << "\n";
		}
		else if (sPrime + revSPrime.substr(1) + tailSPrime == str)
		{
			cout << "1" << "\n";
		}
		else
		{
			cout << "0" << "\n";
		}
	}
	return 0;
}