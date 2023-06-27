#include <iostream>
using namespace std;

int main()
{
	int T;
	long long N;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		if (N % 9 == 0 || N % 3 == 2)
		{
			cout << "TAK" << "\n";
		}
		else
		{
			cout<<"NIE"<<"\n";
		}
	}
	return 0;
}