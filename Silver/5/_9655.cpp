#include <iostream>
using namespace std;

int main()
{
	int N;
	int turns[1001];
	turns[0] = 0;
	turns[1] = 1;
	turns[3] = 1;
	for (int i = 2; i < 1001; i++)
	{
		if (i % 3 != 0)
		{
			turns[i] = turns[i - 1] + 1;
		}
		else if (i > 3 && i % 3 == 0)
		{
			turns[i] = turns[i - 3] + 1;
		}
	}
	cin >> N;
	if (turns[N] % 2 != 0)
	{
		cout << "SK" << "\n";
	}
	else
	{
		cout << "CY" << "\n";
	}
	return 0;
}