#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct eggInfo
{
	int eggPrice;
	long long profit;
	eggInfo(int a, long long b)
	{
		eggPrice = a;
		profit = b;
	}
};

bool compare(const eggInfo& e1, const eggInfo& e2)
{
	if (e1.profit > e2.profit)
	{
		return true;
	}
	else if (e1.profit == e2.profit)
	{
		return e1.eggPrice < e2.eggPrice;
	}
	else
	{
		return false;
	}
}

int main()
{
	int N, M;
	long long sum = 0;
	cin >> N >> M;
	int* arr = new int[M];
	for (int i = 0; i < M; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + M);
	int standard = arr[0];
	vector<eggInfo> eggs;
	for (int i = 0; i < M; i++)
	{
		standard = arr[i];
		for (int j = i; j < M; j++)
		{
			if (j-i >= N)
			{
				break;
			}
			if (arr[j] < standard)
			{
				break;
			}
			sum += standard;
		}
		eggs.push_back(eggInfo(standard, sum));
		sum = 0;
	}
	sort(eggs.begin(), eggs.end(), compare);
	cout << eggs.at(0).eggPrice<< " " << eggs.at(0).profit << "\n";
	return 0;
}