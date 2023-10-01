#include <iostream>
#include <queue>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, num;
	cin >> N;
	priority_queue<int> left; //큰 것부터
	priority_queue<int, vector<int>, greater<int>> right; //작은 것부터
	int mid;
	for (int i = 1; i <= N; i++)
	{
		cin >> num;
		if (i == 1)
		{
			mid = num;
		}
		else
		{
			if (mid <= num && i % 2 ==0)
			{
				right.push(num);
			}
			else if (mid <= num && i % 2 != 0)
			{
				right.push(num);
				left.push(mid);
				mid = right.top();
				right.pop();
			}
			else if (mid > num && i % 2 == 0)
			{
				left.push(num);
				right.push(mid);
				mid = left.top();
				left.pop();
			}
			else
			{
				left.push(num);
			}
		}
		cout << mid << "\n";
	}
	return 0;
}