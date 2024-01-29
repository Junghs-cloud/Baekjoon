#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int N;
	int player1 = 0;
	int player2 = 0;
	char winner;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> winner;
		if (winner == 'D')
		{
			player1++;
		}
		else
		{
			player2++;
		}
		if (abs(player1 - player2) == 2)
		{
			break;
		}
	}
	cout << player1 << ":"<< player2 << "\n";
	return 0;
}