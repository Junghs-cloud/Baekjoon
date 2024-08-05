#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	bool canFind = false;
	for (int i = 1; i <= N; i++)
	{
		string str = to_string(i);
		int sum = i;
		for (int i = 0; i < str.length(); i++)
		{
			sum += str[i] - 48;
		}
		if (sum == N)
		{
			canFind = true;
			cout << i << "\n";
			break;
		}
	}

	if (canFind == false)
	{
		cout << 0 << "\n";
	}
	return 0;
}