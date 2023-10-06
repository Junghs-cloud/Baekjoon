#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T, N;
	cin >> T;
	char* arr = new char[1000001];
	arr[1] = 'k';
	arr[2] = 'c';
	for (int i = 0; i <= 1000000; i++)
	{
		arr[i] = 'c';
	}
	for (int i = 1; i * i <= 1000000; i++)
	{
		arr[i * i] = 'k';
	}
	for (int i = 2; i <= 1000000; i++)
	{
		if (arr[i] == 'c')
		{
			for (int j = 1; j * j + i <= 1000000; j++)
			{
				arr[i + j * j] = 'k';
			}
		}
	}
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		if (arr[N] == 'k')
		{
			cout << "koosaga"<<"\n";
		}
		else
		{
			cout << "cubelover" << "\n";
		}
	}
	return 0;
}