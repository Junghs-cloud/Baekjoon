#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, W, H;
	cin >> N;
	pair<int, int>* PPIs = new pair<int, int>[N];
	for (int i = 0; i < N; i++)
	{
		cin >> W >> H;
		PPIs[i].first = -(W * W + H * H);
		PPIs[i].second = i+1;
	}
	sort(PPIs, PPIs + N);
	for (int i = 0; i < N; i++)
	{
		cout << PPIs[i].second << "\n";
	}
	return 0;
}