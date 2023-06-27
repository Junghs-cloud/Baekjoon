#include <iostream>
using namespace std;

int main()
{
	int N;
	int T;
	long long** fiboCount = new long long*[41];
	for (int i = 0; i < 41; i++)
	{
		fiboCount[i] = new long long[2];
	}
	fiboCount[0][0] = 1;
	fiboCount[0][1] = 0;
	fiboCount[1][0] = 0;
	fiboCount[1][1] = 1;
	for (int i = 2; i < 41; i++)
	{
		fiboCount[i][0] = fiboCount[i - 1][0] + fiboCount[i - 2][0];
		fiboCount[i][1] = fiboCount[i - 1][1] + fiboCount[i - 2][1];
	}
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		cout << fiboCount[N][0] << " " << fiboCount[N][1] << "\n";
	}
	return 0;
}