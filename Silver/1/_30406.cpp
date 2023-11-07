#include <iostream>
#include <cmath>
using namespace std;
int* presents = new int[4];
int answer = 0;

void getPoints(int N, int A, int B)
{
	int minPresent = min(presents[A], presents[B]);
	answer += N * minPresent;
	presents[A] -= minPresent;
	presents[B] -= minPresent;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int num;
	cin >> N;

	for (int i = 0; i < 4; i++)
	{
		presents[i] = 0;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		presents[num]++;
	}
	getPoints(3, 0, 3);
	getPoints(3, 1, 2);

	getPoints(2, 0, 2);
	getPoints(2, 1, 3);

	getPoints(1, 0, 1);
	getPoints(1, 2, 3);
	
	cout << answer << "\n";
	return 0;
}