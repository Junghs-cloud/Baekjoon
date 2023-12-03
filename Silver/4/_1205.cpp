#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

bool cmp(pair<int, bool> p1, pair<int, bool> p2)
{
	return p1.first > p2.first;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, score, P;
	int currentRanking = 1;
	int temp = 0;
	cin >> N>>score>>P;
	bool b = false;
	pair<int, bool>* arr = new pair<int, bool>[N+1];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].first;
		arr[i].second = false;
	}
	arr[N].first = score;
	arr[N].second = true;
	stable_sort(arr, arr + N + 1, cmp);
	for (int i = 0; i < P; i++)
	{
		if (i == 0)
		{
			if (arr[i].second == true)
			{
				cout << currentRanking << "\n";
				b = true;
				break;
			}
		}
		else
		{
			if (arr[i].first != arr[i - 1].first)
			{
				currentRanking=currentRanking+temp+1;
				temp = 0;
			}
			else
			{
				temp++;
			}
			if (arr[i].second == true)
			{
				cout << currentRanking<<"\n";
				b = true;
				break;
			}
		}
	}
	if (b == false)
	{
		cout << "-1" << "\n";
	}
	
	return 0;
}