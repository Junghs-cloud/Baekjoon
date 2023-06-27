#include <iostream>
using namespace std;

int main()
{
	long long K;
	long long a, b, c, d;
	cin >> K;
	cin >> a >> b >> c >> d;
	if (a * K + b == c * K + d)
	{
		cout << "Yes" << " " << a * K + b << "\n";
	}
	else
	{
		cout << "No" << "\n";
	}
	return 0;
}