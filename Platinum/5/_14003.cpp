#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* arr = new int[N];
	int* indexes = new int[N];
	stack<int> answer;
	for (int i = 0;i < N; i++)
	{
		cin >> arr[i];
		indexes[i] = 0;
	}
	vector<int> v;
	indexes[0] = 0;
	v.push_back(arr[0]);
	for (int i = 1; i < N; i++)
	{
		if (arr[i] > v.back())
		{
			v.push_back(arr[i]);
			indexes[i] = v.size() - 1;
		}
		else
		{
			int index = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
			v[index] = arr[i];
			indexes[i] = index;
		}
	}
	int currentFindIndex = v.size() - 1;
	for (int i = N - 1; i >= 0; i--)
	{
		if (indexes[i] == currentFindIndex)
		{
			currentFindIndex--;
			answer.push(arr[i]);
		}
	}
	cout << v.size() << "\n";
	while (!answer.empty())
	{
		cout << answer.top() << " ";
		answer.pop();
	}
	return 0;
}