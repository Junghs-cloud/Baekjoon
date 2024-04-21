#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N>>M;
	int* arrA = new int[N];
	int* arrB = new int[M];
	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		cin >> arrA[i];
	}
	for (int i = 0; i < M; i++)
	{
		cin >> arrB[i];
	}
	sort(arrA, arrA + N);
	sort(arrB, arrB + M);
	for (int i = 0; i < N; i++)
	{
		if (binary_search(arrB, arrB + M, arrA[i]) == false)
		{
			v.push_back(arrA[i]);
		}
	}
	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++)
	{
		cout << v.at(i) << " ";
	}
	return 0;
}