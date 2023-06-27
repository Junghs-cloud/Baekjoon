#include <iostream>
using namespace std;
int bugs = 1;
int N;

void make(int year)
{
	if (year+1 <= N)
	{
		bugs++;
		make(year + 1);
	}
	if (year + 2 <= N)
	{
		bugs++;
		make(year + 2);
	}
	if (year + 3 <= N)
	{
		bugs++;
		make(year + 3);
		if (year % 2 == 1)
		{
			bugs--;
		}
	}
	if (year + 4 <= N && year % 2 ==0)
	{
		bugs++;
		make(year + 4);
		bugs--;
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	N;
	cin >> N;
	make(1);
	cout << bugs << "\n";
	return 0;
}