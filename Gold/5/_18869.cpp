#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	int num;
	int answer = 0;
	cin >> N >> M;
	vector<int>* arr = new vector<int>[N];
	for (int i = 0; i < N; i++)
	{
		vector<int> indexes;
		vector<int> temp;
		for (int j = 0; j < M; j++)
		{
			cin >> num;
			indexes.push_back(num);
			temp.push_back(num);
		}
		sort(indexes.begin(), indexes.end());
		for (int j = 0; j < M; j++)
		{
			int index = lower_bound(indexes.begin(), indexes.end(), temp.at(j))- indexes.begin();
			arr[i].push_back(index);
		}
	}
	sort(arr, arr + N);
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			bool isDiff = false;
			for (int k = 0; k < M; k++)
			{
				if (arr[i].at(k) != arr[j].at(k))
				{
					isDiff = true;
					break;
				}
			}
			if (isDiff == true)
			{
				break;
			}
			else
			{
				answer++;
			}
		}
	}
	cout << answer << "\n";
	return 0;
}