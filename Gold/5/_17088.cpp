#include <iostream>
using namespace std;
int N;
int* arr;
int* temp;
int canNotMake;
int answer;

void check(int i)
{
	int operationCount = i;
	int d = temp[1] - temp[0];
	bool canNotMakeBool = false;
	for (int i = 2; i < N; i++)
	{
		if (temp[i] - temp[i - 1] == d + 1)
		{
			temp[i]--;
			operationCount++;
		}
		else if (temp[i] - temp[i - 1] == d - 1)
		{
			temp[i]++;
			operationCount++;
		}
		else if (temp[i] - temp[i - 1] == d)
		{
			continue;
		}
		else
		{
			canNotMakeBool = true;
			canNotMake++;
			break;
		}
	}
	if (canNotMakeBool==false && operationCount < answer)
	{
		answer = operationCount;
	}
}

void reset()
{
	for (int i = 0; i < N; i++)
	{
		temp[i] = arr[i];
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	arr = new int[N];
	temp = new int[N];
	answer = 10000000;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		temp[i] = arr[i];
	}
	if (N >= 2)
	{
		temp[0] = arr[0] + 1;
		temp[1] = arr[1] + 1;
		check(2);
		reset();

		temp[0] = arr[0] + 1;
		temp[1] = arr[1];
		check(1);
		reset();

		temp[0] = arr[0] + 1;
		temp[1] = arr[1] - 1;
		check(2);
		reset();

		temp[0] = arr[0];
		temp[1] = arr[1] + 1;
		check(1);
		reset();

		temp[0] = arr[0];
		temp[1] = arr[1];
		check(0);
		reset();

		temp[0] = arr[0];
		temp[1] = arr[1] - 1;
		check(1);
		reset();

		temp[0] = arr[0] - 1;
		temp[1] = arr[1] + 1;
		check(2);
		reset();

		temp[0] = arr[0] - 1;
		temp[1] = arr[1];
		check(1);
		reset();

		temp[0] = arr[0] - 1;
		temp[1] = arr[1] - 1;
		check(2);
		reset();

		if (canNotMake == 9)
		{
			cout << "-1" << "\n";
		}
		else
		{
			cout << answer << "\n";
		}
	}
	else
	{
		cout << "0" << "\n";
	}
	return 0;
}