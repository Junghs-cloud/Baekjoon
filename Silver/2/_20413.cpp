#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int s, g, p, d;
	string str;

	cin >> N;
	cin >> s >> g >> p >> d;
	cin >> str;

	int BronzeMax = s - 1;
	int silverMax = g - 1;
	int goldMax = p - 1;
	int platinumMax = d - 1;

	int currentMonth = 0;
	int prevMonth = 0;
	int totalMoney = 0;
	for (int i = 0; i < N; i++)
	{
		if (str.at(i) == 'B')
		{
			currentMonth = BronzeMax - prevMonth;
		}
		else if (str.at(i) == 'S')
		{
			currentMonth = silverMax - prevMonth;
		}
		else if (str.at(i) == 'G')
		{
			currentMonth = goldMax - prevMonth;
		}
		else if (str.at(i) == 'P')
		{
			currentMonth = platinumMax - prevMonth;
		}
		else
		{
			currentMonth = d;
		}
		prevMonth = currentMonth;
		totalMoney += currentMonth;
	}
	cout << totalMoney << "\n";
	return 0;
}