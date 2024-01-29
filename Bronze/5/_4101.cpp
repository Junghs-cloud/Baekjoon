#include <iostream>
using namespace std;

int main()
{
	int N, M;
	while (true)
	{
		cin >> N >> M;
		if (N == 0 && M == 0)
		{
			break;
		}
		else
		{
			if (N > M)
			{
				cout << "Yes"<<"\n";
			}
			else
			{
				cout << "No"<<"\n";
			}
		}
	}
	return 0;
}