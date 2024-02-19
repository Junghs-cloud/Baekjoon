#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int* arr;
map<int, int> m;
map<int, int>::iterator it1;
map<int, int>::iterator it2;
bool isGoodNumber;
long long answer = 0;
void binarySearch(int left, int right, int a, int b)
{
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] == a + b)
		{
			it1 = m.find(a);
			it2 = m.find(b);
			if (it2 == m.end())
			{
				break;
			}
			if (a == 0 && it2->second == 1 || b == 0 && it1->second == 1)
			{
				break;
			}
			answer++;
			isGoodNumber = true;
			break;
		}
		else if (arr[mid] < a + b)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		it1 = m.find(arr[i]);
		if (it1 == m.end())
		{
			m.insert({ arr[i], 1 });
		}
		else
		{
			it1->second++;
		}
	}
	sort(arr, arr + N);
	for (int i = 0; i < N; i++)
	{
		isGoodNumber = false;
		for (int j = 0; j < N; j++)
		{
			if (isGoodNumber == false)
			{
				if (arr[i] == 0 && arr[j] == 0)
				{
					it1 = m.find(0);
					if (it1->second >= 3)
					{
						answer++;
						isGoodNumber = true;
					}
				}
				else if (arr[j] == arr[i] - arr[j])
				{
					it1 = m.find(arr[j]);
					if (it1->second > 1)
					{
						answer++;
						isGoodNumber = true;
					}
				}
				else
				{
					binarySearch(0, N - 1, arr[j], arr[i] - arr[j]);
				}
			}
		}
	}
	cout << answer << "\n";
	return 0;
}