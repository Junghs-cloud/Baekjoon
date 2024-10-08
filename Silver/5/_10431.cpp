#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int P, T;
	cin >> P;
	for (int p = 0; p < P; p++)
	{
		cin >> T;
		int* arr = new int[20];
		int answer = 0;
		list<int>::iterator it;
		list<int> ls;
		for (int i = 0; i < 20; i++)
		{
			cin >> arr[i];
		}
		ls.push_back(arr[0]);
		for (int i = 1; i < 20; i++)
		{
			for (it = ls.begin(); it != ls.end(); it++)
			{
				if (arr[i] < *it)
				{
					answer += distance(it, ls.end());
					ls.insert(it, arr[i]);
					break;
				}
			}
			if (it == ls.end())
			{
				ls.push_back(arr[i]);
			}
		}
		cout <<T<<" " << answer << "\n";
	}
	return 0;
}