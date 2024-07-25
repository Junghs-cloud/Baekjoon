#include <iostream>
#include <string>
using namespace std;

int  main()
{
	long long a, b, c;
	cin >> a >> b >> c;
	long long sum = a * b * c;
	string str = to_string(sum);
	int* digits = new int[10];
	for (int i = 0; i < 10; i++)
	{
		digits[i] = 0;
	}
	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '0')
		{
			digits[0]++;
		}
		else
		{
			int index = str.at(i) - 48;
			digits[index]++;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		cout << digits[i] << "\n";
	}
	return 0;
}