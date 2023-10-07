#include <iostream>
using namespace std;
int* answers;
int* arr;
bool* isVisited;
void backTracking(int depth, int index, int N)
{
	if (depth == 6)
	{
		for (int i = 0; i < 6; i++)
		{
			cout << answers[i] << " ";
		}
		cout << "\n";
	}
	else
	{
		for (int i = index; i < N; i++)
		{
			if (isVisited[i] == false)
			{
				isVisited[i] = true;
				answers[depth] = arr[i];
				backTracking(depth + 1, i, N);
				isVisited[i] = false;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	bool first = true;
	answers = new int[6];
	while (true)
	{
		cin >> N;
		if (N == 0)
		{
			break;
		}
		arr = new int[N];
		isVisited = new bool[N];
		if (first == false)
		{
			cout << "\n";
		}
		for (int i = 0; i < N; i++)
		{
			isVisited[i] = false;
			cin >> arr[i];
		}
		first = false;
		backTracking(0, 0, N);
	}
	return 0;
}