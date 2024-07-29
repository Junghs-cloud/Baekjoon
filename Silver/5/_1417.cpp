#include <iostream>
#include <queue>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, dasom;
	int num;
	int minAnswer = 0;
	cin >> N;
	priority_queue<int, vector<int>> pq;
	cin >> dasom;
	for (int i = 1; i < N; i++)
	{
		cin >> num;
		pq.push(num);
	}
	while (!pq.empty())
	{
		int top = pq.top();
		pq.pop();
		if (top >= dasom)
		{
			dasom++;
			minAnswer++;
			pq.push(top - 1);
		}
	}
	std::cout << minAnswer << "\n";
	return 0;
}