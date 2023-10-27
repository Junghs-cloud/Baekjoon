#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;
pair<int, int>* arr;
int* origin;
bool* isBombed;
int bombCount;
int N;

bool compare(pair<int, int>& p1, pair<int, int>& p2)
{
	if (p1.first > p2.first)
	{
		return true;
	}
	else if (p1.first == p2.first)
	{
		return p1.second < p2.second;
	}
	else
	{
		return false;
	}
}

void chainBomb(int power, int pos, string dir)
{
	if (isBombed[pos] == true || pos== N || pos < 0)
	{
		return;
	}
	else
	{
		if (power > origin[pos])
		{
			bombCount++;
			isBombed[pos] = true;
			if (dir == "left")
			{
				chainBomb(origin[pos], pos - 1, "left");
			}
			else
			{
				chainBomb(origin[pos], pos + 1, "right");
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	arr=new pair<int, int>[N];
	origin = new int[N];
	 isBombed= new bool[N];
	 vector<int> answers;
	for (int i = 0; i < N; i++)
	{
		isBombed[i] = false;
		cin >> origin[i];
		arr[i] = make_pair(origin[i], i);
	}
	sort(arr, arr + N, compare);
	for (int i = 0; i < N; i++)
	{
		if (bombCount == N)
		{
			break;
		}
		else
		{
			if (isBombed[arr[i].second] == true)
			{
				continue;
			}
			answers.push_back(arr[i].second + 1);
			isBombed[arr[i].second] = true;
			chainBomb(arr[i].first, arr[i].second - 1, "left");
			chainBomb(arr[i].first, arr[i].second + 1, "right");
		}
	}
	sort(answers.begin(), answers.end());
	for (int i = 0; i < answers.size(); i++)
	{
		cout << answers.at(i) << "\n";
	}
	return 0;
}