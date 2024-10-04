#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int answer = -1;
	for (int i = N/5; i >=0; i --)
	{
		int last = N - i * 5;
		if (last % 2 == 0)
		{
			answer = last / 2 + i;
			break;
		}
	}
	cout << answer << "\n";
	return 0;
}