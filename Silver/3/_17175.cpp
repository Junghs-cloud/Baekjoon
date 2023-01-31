#include <iostream>
using namespace std;

long long fibo[51];

int main()
{
	int N;
	fibo[0] = 1;
	fibo[1] = 1;
	for (int i = 2; i < 51; i++)
	{
		fibo[i] = ((fibo[i - 1] + fibo[i - 2] + 1 )% 1000000007);
	}
	cin >> N;
	cout << fibo[N]<<"\n";
	return 0;
}