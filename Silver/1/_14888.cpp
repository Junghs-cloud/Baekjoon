#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
long long* arr;
long long* operators;
long long answer;
vector<long long> v;

void backTracking(int depth)
{
	if (depth == N - 1)
	{
		v.push_back(answer);
		return;
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			if (operators[i] != 0)
			{
				if (i == 0)
				{
					answer += arr[depth+1];
					operators[i]--;
					backTracking(depth + 1);
					answer -= arr[depth + 1];
					operators[i]++;
				}
				else if (i == 1)
				{
					answer -= arr[depth + 1];
					operators[i]--;
					backTracking(depth + 1);
					answer += arr[depth + 1];
					operators[i]++;
				}
				else if (i == 2)
				{
					long long temp = answer;
					answer *= arr[depth + 1];
					operators[i]--;
					backTracking(depth + 1);
					answer = temp;
					operators[i]++;
				}
				else
				{
					long long temp = answer;
					answer /= arr[depth + 1];
					operators[i]--;
					backTracking(depth + 1);
					answer = temp;
					operators[i]++;
				}
			}
		}
	}
}

int main()
{
	cin >> N;
	arr = new long long[N];
	operators = new long long[4];
	for (int i = 0; i < N; i++)
	{
		cin>>arr[i];
	}
	for (int i = 0; i < 4; i++)
	{
		cin>>operators[i];
	}
	answer += arr[0];
	backTracking(0);
	sort(v.begin(), v.end());
	cout << v.at(v.size() - 1) << "\n";
	cout << v.at(0) << "\n";
	return 0;
}