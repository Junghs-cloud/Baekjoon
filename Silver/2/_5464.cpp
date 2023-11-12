#include <iostream>
#include <utility>
#include <queue>
using namespace std;

struct park
{
	int weight;
	int carNum;
	bool isFill;
};

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	int k;
	cin >> N >> M;
	park* parks= new park[N];
	int* weights = new int[M];
	queue<int> q;
	long long answer = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> parks[i].weight;
		parks[i].carNum = 0;
		parks[i].isFill = false;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> weights[i];
	}
	for (int i = 0; i < 2 * M; i++)
	{
		cin >> k;
		if (k > 0)
		{
			bool canPark = false;
			for (int i = 0; i < N; i++)
			{
				if (parks[i].isFill == false)
				{
					parks[i].isFill = true;
					parks[i].carNum = k;
					canPark = true;
					break;
				}
			}
			if (canPark == false)
			{
				q.push(k);
			}
		}
		else
		{
			int tempPark = -1;
			for (int i = 0; i < N; i++)
			{
				if (parks[i].carNum == -k)
				{
					answer += (parks[i].weight * weights[(-k) - 1]);
					parks[i].carNum = 0;
					parks[i].isFill = false;
					tempPark = i;
					break;
				}
			}
			if (!q.empty())
			{
				int frontCar = q.front();
				parks[tempPark].carNum = frontCar;
				parks[tempPark].isFill = true;
				q.pop();
			}
		}
	}
	cout << answer << "\n";
	return 0;
}