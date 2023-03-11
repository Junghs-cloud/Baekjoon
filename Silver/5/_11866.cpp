#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int N, K;
	queue<int> numbers;
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		numbers.push(i);
	}
	cout << "<";
	while (!numbers.empty())
	{
		for (int i = 0; i < K - 1; i++)
		{
			int temp = numbers.front();
			numbers.pop();
			numbers.push(temp);
		}
		int current = numbers.front();
		if (numbers.size() != 1)
		{
			cout << current << ", ";
		}
		else
		{
			cout << current;
		}
		numbers.pop();
	}
	cout << ">\n";
	return 0;
}