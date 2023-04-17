#include <iostream>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	if (100 * N >= M)
	{
		cout << "Yes" << "\n";
	}
	else
	{
		cout << "No" << "\n";
	}
	return 0;
}