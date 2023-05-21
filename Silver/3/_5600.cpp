#include <iostream>
#include <queue>
using namespace std;
int zero, one, two=0;
int* arr;
struct state
{
	int i;
	int j;
	int k;
	state(int a, int b, int c)
	{
		i = a;
		j = b;
		k = c;
	}
};

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b, c;
	int i, j, k, r;
	int N;
	cin >> a >> b >> c;
	arr = new int[a + b + c + 1];
	queue<state> q;
	for (int i = 0; i < a + b + c + 1; i++)
	{
		arr[i] = 2;
	}
	cin >> N;
	for (int A = 0; A < N; A++)
	{
		cin >> i >> j >> k >> r;
		if (r == 1)
		{
			arr[i] = 1;
			arr[j] = 1;
			arr[k] = 1;
		}
		else
		{
			q.push(state(i, j, k));
		}
	}
	while (!q.empty())
	{
		state currentFront = q.front();
		int normalCount = 0;
		if (arr[currentFront.i] == 1)
		{
			normalCount++;
		}
		if (arr[currentFront.j] == 1)
		{
			normalCount++;
		}
		if (arr[currentFront.k] == 1)
		{
			normalCount++;
		}
		if (normalCount == 2)
		{
			if (arr[currentFront.i] != 1)
			{
				arr[currentFront.i] = 0;
			}
			if (arr[currentFront.j] != 1)
			{
				arr[currentFront.j] = 0;
			}
			if (arr[currentFront.k] != 1)
			{
				arr[currentFront.k] = 0;
			}
		}
		q.pop();
	}
	for (int A = 1; A <= (a + b + c); A++)
	{
		cout << arr[A] << "\n";
	}
	return 0;
}