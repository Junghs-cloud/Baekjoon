#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int N, M, num;
		cin >> N;
		int* note1 = new int[N];
		for (int i = 0; i < N; i++)
		{
			cin >> note1[i];
		}
		sort(note1, note1 + N);
		cin >> M;
		for (int i = 0; i < M; i++)
		{
			cin >> num;
			if (binary_search(note1, note1 + N, num) == true)
			{
				cout << 1 << "\n";
			}
			else
			{
				cout << 0 << "\n";
			}
		}
	}
	return 0;
}