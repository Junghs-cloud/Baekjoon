#include <iostream>
using namespace std;

int main()
{
	int N;
	int count = 0;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		if (i % 125 == 0)
		{
			count += 3;
		}
		else if (i % 25 == 0)
		{
			count += 2;
		}
		else if (i % 5==0)
		{
			count++;
		}
	}
	cout << count << "\n";
	return 0;
}