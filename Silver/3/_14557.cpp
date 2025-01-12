#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int R, C;
	cin >> R >> C;
	long long minAnswer = R * C / 2;
	long long maxAnswer = R * C - 1;
	cout << minAnswer << " " << maxAnswer << "\n";
	return 0;
}