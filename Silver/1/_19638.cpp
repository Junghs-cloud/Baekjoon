#include <iostream>
#include <queue>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, H, T;
	int height;
	int count = 0;
	bool canMake = false;
	priority_queue<int, vector<int>, less<int>> pq;
	cin >> N >> H >> T;
	for (int i = 0; i < N; i++)
	{
		cin >> height;
		pq.push(height);
	}
	if (H > pq.top())
	{
		canMake = true;
		cout << "YES" << "\n";
		cout << count << "\n";
	}
	while (canMake==false && count< T)
	{
		count++;
		int tallest = pq.top();
		if (tallest == 1)
		{
			break;
		}
		pq.pop();
		pq.push(tallest / 2);
		if (H > pq.top())
		{
			canMake = true;
			cout << "YES" << "\n";
			cout << count << "\n";
			break;
		}
	}
	if (canMake == false)
	{
		cout << "NO" << "\n";
		cout << pq.top() << "\n";
	}
	return 0;
}