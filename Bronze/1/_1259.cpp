#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string N;
	while (true)
	{
		cin >> N;
		bool isPelindrome = true;
		if (N == "0")
		{
			break;
		}
		else
		{
			int strLength = N.length();
			for (int i = 0; i < strLength / 2; i++)
			{
				if (N[i] != N[strLength -1 - i])
				{
					isPelindrome = false;
					break;
				}
			}
			if (isPelindrome == true)
			{
				cout << "yes"<<"\n";
			}
			else
			{
				cout << "no" << "\n";
			}
		}
	}

	return 0;
}