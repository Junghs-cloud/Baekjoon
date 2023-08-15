#include <iostream>
using namespace std;

int main()
{
	string str1;
	string str2;
	cin >> str1;
	cin >> str2;
	int a = 0;
	int b = 0;
	int sum = 0;
	for (int i = 0; i < str1.length(); i++)
	{
		if (str1[i] == 'M')
		{
			a += 1000;
		}
		if (str1[i] == 'D')
		{
			a += 500;
		}
		if (str1[i] == 'C')
		{
			if (i != str1.length() - 1 && (str1[i + 1] == 'D' || str1[i + 1] == 'M'))
			{
				a -= 100;
			}
			else
			{
				a += 100;
			}

		}
		if (str1[i] == 'L')
		{
			a += 50;
		}
		if (str1[i] == 'X')
		{
			if (i != str1.length() - 1 && (str1[i + 1] == 'L' || str1[i + 1] == 'C'))
			{
				a -= 10;
			}
			else
			{
				a += 10;
			}
		}
		if (str1[i] == 'V')
		{
			a +=5;
		}
		if (str1[i] == 'I')
		{
			if (i != str1.length() - 1 && (str1[i + 1] == 'V' || str1[i + 1] == 'X'))
			{
				a -= 1;
			}
			else
			{
				a += 1;
			}

		}
	}

	for (int i = 0; i < str2.length(); i++)
	{
		if (str2[i] == 'M')
		{
			b += 1000;
		}
		if (str2[i] == 'D')
		{
			b += 500;
		}
		if (str2[i] == 'C')
		{
			if (i != str2.length() - 1 && (str2[i + 1] == 'D' || str2[i + 1] == 'M'))
			{
				b -= 100;
			}
			else
			{
				b += 100;
			}
		}
		if (str2[i] == 'L')
		{
			b += 50;
		}
		if (str2[i] == 'X')
		{
			if (i != str2.length() - 1 && (str2[i + 1] == 'L' || str2[i + 1] == 'C'))
			{
				b -= 10;
			}
			else
			{
				b += 10;
			}

		}
		if (str2[i] == 'V')
		{
			b += 5;
		}
		if (str2[i] == 'I')
		{
			if (i != str2.length() - 1 && (str2[i + 1] == 'V' || str2[i + 1] == 'X'))
			{
				b -= 1;
			}
			else
			{
				b += 1;
			}

		}
	}
	string sumStr = "";
	sum = a + b;
	cout << sum << "\n";
	while (sum != 0)
	{
		if (sum / 1000 != 0)
		{
			sumStr += "M";
			sum -= 1000;
		}
		else if (sum / 500 != 0)
		{
			if (sum / 100 == 9)
			{
				sumStr += "CM";
				sum -= 900;
			}
			else
			{
				sumStr += "D";
				sum -= 500;
			}

		}
		else if (sum / 100 != 0)
		{
			if (sum / 100 == 4)
			{
				sumStr += "CD";
				sum -= 400;
			}
			else
			{
				sumStr += "C";
				sum -= 100;
			}
		}
		else if (sum / 50 != 0)
		{
			if (sum / 10 == 9)
			{
				sumStr += "XC";
				sum -= 90;
			}
			else
			{
				sumStr += "L";
				sum -= 50;
			}

		}
		else if (sum / 10 != 0)
		{
			if (sum / 10 == 4)
			{
				sumStr += "XL";
				sum -= 40;
			}
			else
			{
				sumStr += "X";
				sum -= 10;
			}
		}
		else if (sum / 5 != 0)
		{
			if (sum == 9)
			{
				sumStr += "IX";
				sum -= 9;
			}
			else
			{
				sumStr += "V";
				sum -= 5;
			}
		}
		else if (sum / 1 != 0)
		{
			if (sum == 4)
			{
				sumStr += "IV";
				sum -= 4;
			}
			else
			{
				sumStr += "I";
				sum -= 1;
			}

		}
	}
	cout << sumStr << "\n";
	return 0;
}