#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <utility>
using namespace std;
map<int, set<int>> problems;
map<int, set<int>>::iterator it;

struct hardCmp
{
	bool operator()(pair<int, int>& p1, pair<int, int>& p2)
	{
		if (p1.first > p2.first)
		{
			return false;
		}
		else if (p1.first == p2.first)
		{
			return p1.second < p2.second;
		}
		else
		{
			return true;
		}
	}
};

struct easyCmp
{
	bool operator()(pair<int, int>& p1, pair<int, int>& p2)
	{
		if (p1.first < p2.first)
		{
			return false;
		}
		else if (p1.first == p2.first)
		{
			return p1.second > p2.second;
		}
		else
		{
			return true;
		}
	}
};

priority_queue<pair<int, int>, vector<pair<int, int>>, hardCmp> hardProblemQueue;
priority_queue<pair<int, int>, vector<pair<int, int>>, easyCmp> easyProblemQueue;

void addProblem(int problemNum, int difficulty)
{
	it = problems.find(problemNum);
	if (it == problems.end())
	{
		set<int> s;
		s.insert(difficulty);
		problems.insert({ problemNum, s });
	}
	else
	{
		it->second.insert(difficulty);
	}
	hardProblemQueue.push(make_pair(difficulty, problemNum));
	easyProblemQueue.push(make_pair(difficulty, problemNum));
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	int problemNum, difficulty, flag;
	string query;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> problemNum >> difficulty;
		addProblem(problemNum, difficulty);
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> query;
		if (query == "add")
		{
			cin >> problemNum >> difficulty;
			addProblem(problemNum, difficulty);
		}
		else if (query == "recommend")
		{
			cin >> flag;
			if (flag == 1)
			{
				while (true)
				{
					pair<int, int> top = hardProblemQueue.top();
					it = problems.find(top.second);
					if (it == problems.end())
					{
						hardProblemQueue.pop();
					}
					else
					{
						set<int> problemDifficulty = it->second;
						if (problemDifficulty.find(top.first) == problemDifficulty.end())
						{
							hardProblemQueue.pop();
						}
						else
						{
							cout << top.second << "\n";
							break;
						}
					}
				}
			}
			else
			{
				while (true)
				{
					pair<int, int> top = easyProblemQueue.top();
					it = problems.find(top.second);
					if (it == problems.end())
					{
						easyProblemQueue.pop();
					}
					else
					{
						set<int> problemDifficulty = it->second;
						if (problemDifficulty.find(top.first) == problemDifficulty.end())
						{
							easyProblemQueue.pop();
						}
						else
						{
							cout << top.second << "\n";
							break;
						}
					}
				}
			}
		}
		else
		{
			cin >> problemNum;
			problems.erase(problemNum);
		}
	}
	return 0;
}