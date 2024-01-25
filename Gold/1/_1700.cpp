#include <iostream>
#include <queue>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	int num;
	cin >> N >> M;
	queue<int>* q = new queue<int>[M+1];
	deque<int> multitab;
	int* arr = new int[M];
	int answer = 0;
	for (int i = 0; i < M; i++)
	{
		cin >> num;
		q[num].push(i);
		arr[i] = num;
	}
	for (int i = 0; i < M; i++)
	{
		num = arr[i];
		if (multitab.size() < N)
		{
			bool b = false;
			for (int j = 0; j < multitab.size(); j++)
			{
				if (multitab[j] == num)
				{
					b = true;
					break;
				}
			}
			if (b == false)
			{
				multitab.push_back(num);
			}
			q[num].pop();
		}
		else
		{
			bool b = false;
			for (int j = 0; j < multitab.size(); j++)
			{
				if (multitab[j] == num)
				{
					b = true;
					q[num].pop();
					break;
				}
			}
			if (b == false)
			{
				bool noUseDevice = false;
				int longgest = -1;
				int holeIndex = -1;
				for (int j = 0; j < multitab.size(); j++)
				{
					int device = multitab[j];
					if (q[device].empty())
					{
						noUseDevice = true;
						q[num].pop();
						multitab[j] = num;
						answer++;
						break;
					}
					else
					{
						int first = q[device].front();
						if (first > longgest)
						{
							longgest = first;
							holeIndex = j;
						}
					}
				}
				if (noUseDevice == false)
				{
					q[num].pop();
					multitab[holeIndex] = num;
					answer++;
				}
			}
		}
	}
	cout << answer << "\n";
	return 0;
}