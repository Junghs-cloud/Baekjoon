#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, S;
	int start, time;
	cin >> N >> M >> S;
	pair<int, int>* arr = new pair<int, int>[N];
	int current = 0;
	bool canTakeExam = false;
	for (int i = 0; i < N; i++)
	{
		cin >> start >> time;
		arr[i] = make_pair(start, time);
	}
	sort(arr, arr + N);
	for (int i = 0; i < N; i++)
	{
		if (current + M <= arr[i].first)
		{
			canTakeExam = true;
			cout << current << "\n";
			break;
		}
		else
		{
			current = arr[i].first + arr[i].second;
		}
	}
	if (canTakeExam == false)
	{
		if (current + M <= S)
		{
			cout << current << "\n";
		}
		else
		{
			cout << "-1" << "\n";
		}
	}
	return 0;
}