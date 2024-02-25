#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, L, K;
	int x, y;
	cin >> N >> M >> L >> K;
	vector<pair<int, int>> v;
	int answer = K;
	for (int i = 0; i < K; i++)
	{
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	for (int i = 0; i < K; i++)
	{
		int startX = v.at(i).first;
		for (int j = 0; j < K; j++)
		{
			int startY = v.at(j).second;
			int protect = 0;
			for (int k = 0; k < K; k++)
			{
				pair<int, int> currentShootingStar = v.at(k);
				if (startX <= currentShootingStar.first && currentShootingStar.first <= startX+L && startY <=currentShootingStar.second && currentShootingStar.second <= startY+L)
				{
					protect++;
				}
			}
			answer = min(answer, K - protect);
		}
	}
	cout << answer << "\n";
	return 0;
}