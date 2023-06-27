#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, Q;
	cin >> N >> Q;
	bool* land = new bool[N + 1];
	int landNum;
	int currentNode;
	int firstMeet;
	for (int i = 0; i < N + 1; i++)
	{
		land[i] = false;
	}
	for (int i = 0; i < Q; i++)
	{
		cin >> landNum;
		currentNode = landNum;
		firstMeet = 0;
		if (landNum == 1)
		{
			if (land[1] == false)
			{
				cout << "0" << "\n";
				land[1] = true;
			}
			else
			{
				cout << "1" << "\n";
			}
			continue;
		}
		while (currentNode != 1)
		{
			currentNode /= 2;
			if (land[currentNode] == true)
			{
				firstMeet = currentNode;
			}
		}
		if (firstMeet == 0)
		{
			if (land[landNum] == true)
			{
				firstMeet = landNum;
			}
			land[landNum] = true;
		}
		cout << firstMeet << "\n";

	}
	return 0;
}