#include <iostream>
using namespace std;

int N, M;
bool* isVisited;
int* sArr;

void backTracking(int index, int depth)
{
	if (depth == M)
	{
		for (int i = 0; i < depth; i++)
		{
			cout << sArr[i] << " ";
		}
		cout << "\n";
		return;

	}
	else
	{
		for (int i = index; i < N; i++)
		{
			if (isVisited[i] == false)
			{
				isVisited[i] = true;
				sArr[depth] = i+1;
				backTracking(i, depth + 1);
				isVisited[i] = false;
			}
		}
		
	}

}

int main()
{
	cin >> N >> M;
	isVisited = new bool[N];
	sArr = new int[N];
	for (int i = 0; i < N; i++)
	{
		isVisited[i] = false;
	}
	backTracking(0, 0);
	return 0;
}