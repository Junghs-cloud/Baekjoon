#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int A, B, V;
	cin >> A >> B >> V;
	int day = A - B;
	double slipDayDouble = (double)(V - A) / (double)day;
	int slipDayInt = ceil(slipDayDouble);
	cout << slipDayInt + 1 << "\n";
	return 0;
}