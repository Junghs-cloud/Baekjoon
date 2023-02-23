#include <iostream>
using namespace std;

int main()
{
	
	int N;
	cin >> N;
	long long** endsWith = new long long* [N + 1];
	for (int i = 0; i < N + 1; i++)
	{
		endsWith[i] = new long long[2];
	}
	endsWith[1][0] = 0;
	endsWith[1][1] = 1;
	for (int i = 2; i < N + 1; i++)
	{
		endsWith[i][0] = endsWith[i - 1][1] + endsWith[i-1][0];
		endsWith[i][1] = endsWith[i - 1][0];
	}
	cout << endsWith[N][0] + endsWith[N][1]<<"\n";
	return 0;
}