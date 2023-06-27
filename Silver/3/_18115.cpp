#include <iostream>
#include <deque>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	deque<int> d;
	int N;
	int teq;
	cin >> N;
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		d.push_back(i);
	}
	for (int i = 0; i < N; i++)
	{
		cin >> teq;
		int index;
		if (teq == 1)
		{
			index = d.front();
			d.pop_front();
		}
		else if (teq == 2)
		{
			int front = d.front();
			d.pop_front();
			index = d.front();
			d.pop_front();
			d.push_front(front);
		}
		else
		{
			index = d.back();
			d.pop_back();
		}
		arr[index] = N - i;
	}
	for (int i = 0; i < N; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout << "\n";
	return 0;
}