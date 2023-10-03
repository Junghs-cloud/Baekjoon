#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int number;
	cin >> N;
	bool* num = new bool[N];
	for (int i = 0; i < N; i++)
	{
		num[i] = false;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> number;
		if (num[number] == false)
		{
			num[number] = true;
		}
		else
		{
			cout << number<< "\n";
		}
	}
	return 0;
}