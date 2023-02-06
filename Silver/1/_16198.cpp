#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<int> energys;
long long sum = 0;
long long answer = 0;

void collectEnergy(int remain)
{
	if (remain == 2)
	{
		if (answer < sum)
		{
			answer = sum;
		}
		return;
	}
	else
	{
		for (int i = 1; i < (signed) energys.size() - 1; i++)
		{
			int currentTurnEnergy = energys[i - 1] * energys[i + 1];
			int currentEnergy = energys[i];
			energys.erase(energys.begin() + i);
			sum += (long long)currentTurnEnergy;
			collectEnergy( remain - 1);
			sum -= currentTurnEnergy;
			energys.insert(energys.begin() + i, currentEnergy);
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int temp;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		energys.push_back(temp);
	}
	collectEnergy(N);
	cout << answer<<"\n";
	return 0;
}