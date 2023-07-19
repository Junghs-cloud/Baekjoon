#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
char* possible;
char* c;

int L, C;
int vowelCount;
int consonantCount;
bool* isVisited;

void backTracking(int depth, int index)
{
	if (depth == L)
	{
		for (int i = 0; i < L; i++)
		{
			cout << possible[i];
		}
		cout << "\n";
		return;
	}
	else
	{

		for (int i = index; i < C; i++)
		{
			if (depth >= L - 2 && consonantCount == 0 && (c[i] == 'a' || c[i] == 'e' || c[i] == 'i' || c[i] == 'o' || c[i] == 'u'))
			{
				continue;
			}
			if (depth == L - 1 && vowelCount == 0 && !(c[i] == 'a' || c[i] == 'e' || c[i] == 'i' || c[i] == 'o' || c[i] == 'u'))
			{
				continue;
			}
			if (depth == L - 1 && consonantCount == 1 && (c[i] == 'a' || c[i] == 'e' || c[i] == 'i' || c[i] == 'o' || c[i] == 'u'))
			{
				continue;
			}
			if (isVisited[i] == false)
			{
				if (c[i] == 'a' || c[i] == 'e' || c[i] == 'i' || c[i] == 'o' || c[i] == 'u')
				{
					isVisited[i] = true;
					vowelCount++;
					possible[depth] = c[i];
					backTracking(depth + 1, i + 1);
					isVisited[i] = false;
					vowelCount--;
				}
				else
				{
					isVisited[i] = true;
					consonantCount++;
					possible[depth] = c[i];
					backTracking(depth + 1, i + 1);
					isVisited[i] = false;
					consonantCount--;
				}
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	char ch;
	cin >> L >> C;
	possible = new char[L];
	c = new char[C];
	isVisited = new bool[C];
	for (int i = 0; i < C; i++)
	{
		isVisited[i] = false;
		cin >> ch;
		c[i] = ch;
	}
	sort(c, c + C);
	backTracking(0, 0);
	return 0;
}