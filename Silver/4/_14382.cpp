#include <iostream>
#include <string>
using namespace std;

int main()
{
	int T, N;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		int initN = N;

		bool* digits = new bool[10];
		for (int j= 0; j < 10; j++)
		{
			digits[j] = false;
		}
		bool canSleep = false;
		for (int j=1; j <1000; j++)
		{
			string str = to_string(N);
			for (int k = 0; k < str.length(); k++)
			{
				int index = str[k] - 48;
				digits[index] = true;
			}

			bool isAllTrue = true;
			for (int k = 0; k < 10; k++)
			{
				if (digits[k] == false)
				{
					isAllTrue = false;
				}
			}
			if (isAllTrue == true)
			{
				cout <<"Case #"<<i+1<<": " << N << "\n";
				canSleep = true;
				break;
			}
			else
			{
				N += initN;
			}
		}
		if (canSleep == false)
		{
			cout << "Case #" << i + 1 << ": "<<"INSOMNIA\n";
		}
	}

	return 0;
}