#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int* fibo = new int[N + 1];
	fibo[0] = 0;
	fibo[1] = 1;
	for (int i = 2; i < N + 1; i++)
	{
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	cout << fibo[N] << "\n";
	return 0;
}