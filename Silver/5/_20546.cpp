#include <iostream>
using namespace std;

int N;

struct people
{
	int remain = N;
	int haveStock = 0;
};

int main()
{
	cin >> N;
	int* stock = new int[14];
	int up = 0;
	int down = 0;
	people J;
	people S;
	for (int i = 0; i < 14; i++)
	{
		cin >> stock[i];
	}
	for (int i = 0; i < 14; i++)
	{
		if (stock[i] <= J.remain)
		{
			J.haveStock += J.remain / stock[i];
			J.remain = J.remain % stock[i];
		}
	}
	for (int i = 1; i < 14; i++)
	{
		if (stock[i] > stock[i - 1])
		{
			up++;
		}
		else
		{
			up = 0;
		}
		if (stock[i] < stock[i - 1])
		{
			down++;
		}
		else
		{
			down = 0;
		}
		if (up >= 3)
		{
			if (S.haveStock != 0)
			{
				S.remain += stock[i] * S.haveStock;
				S.haveStock = 0;
			}
		}
		if (down >= 3)
		{
			S.haveStock += S.remain / stock[i];
			S.remain = S.remain % stock[i];
		}
	}
	int JSum = J.remain + stock[13] * J.haveStock;
	int SSum = S.remain + stock[13] * S.haveStock;
	if (JSum < SSum)
	{
		cout << "TIMING"<<"\n";
	}
	else if (JSum > SSum)
	{
		cout << "BNP" << "\n";
	}
	else
	{
		cout << "SAMESAME" << "\n";
	}
	return 0;
}