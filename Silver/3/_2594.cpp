#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;

int getTime(string s)
{
	int hour = stoi(s.substr(0, 2));
	int min = stoi(s.substr(2));
	return hour * 60 + min;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	pair<string, string>* arr = new pair<string, string>[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].first >> arr[i].second;
	}
	int prevEnd = 600;
	int answer = 0;
	sort(arr, arr + N);
	for (int i = 0; i < N; i++)
	{
		int currentStart = getTime(arr[i].first) - 10;
		int currentEnd = getTime(arr[i].second)+ 10;
		if (currentStart >= prevEnd)
		{
			answer = max(answer, currentStart - prevEnd);
			prevEnd = currentEnd;
		}
		if (currentEnd >= prevEnd)
		{
			prevEnd = currentEnd;
		}
	}
	answer = max(answer, 1320 - prevEnd);
	cout << answer << "\n";
	return 0;
}