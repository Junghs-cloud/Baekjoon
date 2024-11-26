#include <iostream>
using namespace std;
int N, M;
long long* playLists;
int answer;
int maxCount;

int countBit(long long temp)
{
	if (temp == 0)
	{
		return 0;
	}
	return temp % 2 + countBit(temp / 2);
}

void backTracking(int index, long long bit, int selectedNum)
{
	int bitCount = countBit(bit);
	if (bitCount > maxCount) {
		maxCount = bitCount;
		answer = selectedNum;
	}
	else if (bitCount == maxCount) {
		answer = min(answer, selectedNum);
	}
	if (index == N)
	{
		return;
	}
	backTracking(index + 1, bit | playLists[index], selectedNum + 1);
	backTracking(index + 1, bit, selectedNum);
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str, playList;
	cin >> N >> M;
	playLists = new long long[N];
	answer = -1;
	for (int i = 0; i < N; i++)
	{
		cin >> str >> playList;
		playLists[i] = 0;
		for (int j = 0; j < M; j++)
		{
			int bit = 0;
			if (playList[j] == 'Y')
			{
				bit = 1;
			}
			else
			{
				bit = 0;
			}
			playLists[i] = playLists[i] | ((long long) bit << j);
		}
	}
	backTracking(0, 0, 0);
	cout << answer << "\n";
	return 0;
}