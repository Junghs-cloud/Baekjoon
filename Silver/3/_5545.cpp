#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int& i1, int& i2)
{
	if (i1 > i2)
	{
		return true;
	}
	else return false;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int A, B, C;
	cin >> N;
	cin >> A >> B;
	cin >> C;
	int* topping = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> topping[i];
	}
	sort(topping, topping + N, cmp);
	long long sum = C;
	long long cost = A;
	long long calorie = C / A;
	long long best = calorie;
	for (int i = 0; i < N; i++)
	{
		sum += topping[i];
		A += B;
		if (sum / A > best)
		{
			best = sum / A;
		}
	}
	cout << best << "\n";
	return 0;
}