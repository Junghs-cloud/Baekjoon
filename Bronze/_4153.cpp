#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b, c;
	while (true)
	{
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)
		{
			break;
		}
		else
		{
			int A = a * a;
			int B = b * b;
			int C = c * c;
			if (A + B == C || A + C == B || B + C == A)
			{
				cout<<"right"<<"\n";
			}
			else
			{
				cout << "wrong" << "\n";
			}
		}
	}
	return 0;
}