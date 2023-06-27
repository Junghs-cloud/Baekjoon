#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int A, B;
	bool* arrA = new bool[10];
	bool* arrB = new bool[10];
	bool* arrC = new bool[10];
	for (int i = 0; i < 10; i++)
	{
		arrA[i] = false;
		arrB[i] = false;
		arrC[i] = false;
	}
	cin >> A >> B;
	for (int i = 9; i >= 0; i--)
	{
		if (A >= (int)pow(2, i))
		{
			arrA[i] = true;
			A -= (int)pow(2, i);
		}
		if (B >= (int)pow(2, i))
		{
			arrB[i] = true;
			B -= (int)pow(2, i);
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if (arrA[i] == true && arrB[i] == true || arrA[i] == false && arrB[i] == false)
		{
			arrC[i] = false;
		}
		else
		{
			arrC[i] = true;
		}
	}
	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		if (arrC[i] == true)
		{
			sum += (int)pow(2, i);
		}
	}
	cout << sum << "\n";
	return 0;
}