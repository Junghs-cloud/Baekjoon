#include <iostream>
using namespace std;

int main()
{
	int N;
	int vote;
	int agree = 0;
	int disagree = 0;
	int abstention = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> vote;
		switch (vote)
		{
		case 1: agree++;
			break;
		case -1: disagree++;
			break;
		case 0:abstention++;
			break;
		}
	}
	if (N % 2 == 0 && abstention >= N / 2)
	{
		cout << "INVALID" << "\n";
	}
	else if (N % 2 == 1 && abstention >= N / 2 + 1)
	{
		cout << "INVALID"<<"\n";
	}
	else if (agree > disagree)
	{
		cout << "APPROVED" << "\n";
	}
	else
	{
		cout << "REJECTED"<<"\n";
	}
	return 0;
}