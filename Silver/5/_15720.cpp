#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int B, C, D;
	cin >> B >> C >> D;
	int* hamburgers = new int[B];
	int* sides = new int[C];
	int* drinks = new int[D];
	int maxSetCount = min({ B, C, D });
	int originSum = 0;
	int setSum = 0;
	for (int i = 0; i < B; i++)
	{
		cin >> hamburgers[i];
		originSum += hamburgers[i];
	}
	for (int i = 0; i < C; i++)
	{
		cin >> sides[i];
		originSum += sides[i];
	}
	for (int i = 0; i < D; i++)
	{
		cin >> drinks[i];
		originSum += drinks[i];
	}
	sort(hamburgers, hamburgers + B, greater());
	sort(sides, sides + C, greater());
	sort(drinks, drinks + D, greater());
	for (int i = 0; i < maxSetCount; i++)
	{
		setSum += hamburgers[i] * 0.9;
		setSum += sides[i] * 0.9;
		setSum += drinks[i] * 0.9;
	}
	for (int i = maxSetCount; i < B; i++)
	{
		setSum += hamburgers[i];
	}
	for (int i = maxSetCount; i < C; i++)
	{
		setSum += sides[i];
	}
	for (int i = maxSetCount; i < D; i++)
	{
		setSum += drinks[i];
	}
	cout << originSum << "\n";
	cout << setSum << "\n";
	return 0;
}