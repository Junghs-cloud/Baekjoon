#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, num;
	cin >> N >> M;
	int* arr = new int[N];
	bool* isFriend = new bool[1001];
	int answer = 0;;
	for (int i = 0; i < 1001; i++)
	{
		isFriend[i] = false;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < M; i++)
	{
		cin >> num;
		isFriend[num] = true;
	}
	for (int i = 0; i < M; i++)
	{
		int waitNum = arr[i];
		if (isFriend[waitNum] == false)
		{
			answer++;
		}
	}
	cout << answer << "\n";
	return 0;
}