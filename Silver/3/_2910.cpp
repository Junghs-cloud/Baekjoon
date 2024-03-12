#include <iostream>
#include <algorithm>
#include <map>
#include <utility>
using namespace std;
map<int, pair<int, int>> m;

bool cmp(int i1, int i2)
{
	map<int, pair<int, int>>::iterator it1=m.find(i1);
	map<int, pair<int, int>>::iterator it2=m.find(i2);
	if (it1->second.second > it2->second.second)
	{
		return true;
	}
	else if (it1->second.second == it2->second.second)
	{
		return it1->second.first < it2->second.first;
	}
	else
	{
		return false;
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N>>M;
	map<int, pair<int, int>>::iterator it;
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		it = m.find(arr[i]);
		if (it == m.end())
		{
			m.insert({arr[i],make_pair(i, 1)});
		}
		else
		{
			it->second.second++;
		}
	}
	sort(arr, arr + N, cmp);
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}