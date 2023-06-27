#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N>>M;
	int* numbers = new int[N];
	string* strings = new string[N];
	int fight;
	for (int i = 0; i < N; i++)
	{
		cin >> strings[i]>> numbers[i];
	}
	for (int i = 0; i < M; i++)
	{
		cin >> fight;
		int index = lower_bound(numbers, numbers + N, fight) - numbers;
		cout<<strings[index]<<"\n";
	}
	return 0;
}