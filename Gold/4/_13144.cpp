#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int num;
	vector<int>* v = new vector<int>[100001];
	vector<int>::iterator it;
	cin >> N;
	int* arr = new int[N];
	long long answer = 0;
	for (int i = 0; i < N; i++)
	{
		arr[i] = 1;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		if (v[num].empty())
		{
			if (i == 0)
			{
				arr[i] = 1;
			}
			else
			{
				arr[i] = min(arr[i - 1] + 1, i + 1);
			}
		}
		else
		{
			int length = i - v[num].at(v[num].size() - 1);
			arr[i] = min(length, arr[i-1]+1);
		}
		answer += arr[i];
		v[num].push_back(i);
	}
	cout << answer << "\n";
	return 0;
}