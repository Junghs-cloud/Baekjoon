#include <iostream>
#include <cmath>
using namespace std;
int N;
int* arr;

bool checkPrime(int depth)
{
	int num = 0;
	for (int i = 0; i <= depth; i++)
	{
		num =num*10+arr[i];
	}
	if (num == 1)
	{
		return false;
	}
	bool isPrime = true;
	for (int i = 2; i <= sqrt(num); i++)
	{
		if (num % i == 0)
		{
			isPrime = false;
			break;
		}
	}
	if (isPrime == false)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void backTracking(int depth)
{
	if (depth == N)
	{
		for (int i = 0; i < depth; i++)
		{
			cout << arr[i];
		}
		cout << "\n";
	}
	else
	{
		if (depth == 0)
		{
			for (int i = 2; i <= 9; i++)
			{
				arr[depth] = i;
				if (checkPrime(depth) == true)
				{
					backTracking(depth + 1);
				}
			}
		}
		else
		{
			for (int i = 1; i <= 9; i+=2)
			{
				arr[depth] = i;
				if (checkPrime(depth) == true)
				{
					backTracking(depth + 1);
				}
			}
		}

	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	arr = new int[N];
	backTracking(0);
	return 0;
}