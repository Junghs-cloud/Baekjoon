#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	int a, b;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> a >> b;
		cout << a + b << "\n";
	}
	return 0;
}