#include <iostream>
#include <map>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, B;
	cin >> N >> M >> B;
	map<int, int> m;
	map<int, int>::iterator it;
	int** world = new int*[N];
	for (int i = 0; i < N; i++)
	{
		world[i] = new int[M];
		for (int j = 0; j < M; j++)
		{
			cin >> world[i][j];
			it = m.find(world[i][j]);
			if (it == m.end())
			{
				m.insert({ world[i][j], 1 });
			}
			else
			{
				it->second++;
			}
		}
	}
	int minTime = 200000000;
	int answerHeight = 0;
	for (int expectHeight = m.begin()->first; expectHeight <= prev(m.end())->first; expectHeight++)
	{
		int time = 0;
		long long inventory = B;
		bool canMake = true;

		for (map<int, int>::reverse_iterator searchHeight = m.rbegin(); searchHeight != m.rend(); searchHeight++)
		{
			if (expectHeight < searchHeight->first)
			{
				//땅을 깎는다.
				int gap = (searchHeight->first) - (expectHeight);
				inventory += gap * (searchHeight->second);
				time += gap * 2 * searchHeight->second;
			}
			else if (expectHeight == searchHeight->first)
			{
				//아무것도 안함.
			}
			else
			{
				//인벤토리에서 꺼내 채워넣는다.
				int gap = (expectHeight) - (searchHeight->first);
				inventory -= gap * searchHeight->second;
				time += gap * searchHeight->second;
				if (inventory < 0)
				{
					canMake = false;
				}
			}
		}
		if (canMake == true)
		{
			if (time <= minTime)
			{
				minTime = time;
				answerHeight = expectHeight;
			}
		}
	}
	std::cout << minTime << " " << answerHeight << "\n";
	return 0;
}