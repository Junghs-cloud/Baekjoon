#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	while (true)
	{
		int N;
		double d;
		string s;
		cin >> N;
		if (N == 0)
		{
			break;
		}
		double* heights = new double[N];
		pair<string, double>* names = new pair<string, double>[N];
		for (int i = 0; i < N; i++)
		{
			cin >> s >> d;
			names[i].first = s;
			names[i].second = d;
			heights[i] = -d;
		}
		sort(heights, heights + N);
		double maxHeight = heights[0];
		for (int i = 0; i < N; i++)
		{
			if (names[i].second == -maxHeight)
			{
				std::cout << names[i].first << " ";
			}
		}
		std::cout << "\n";
	}
	return 0;
}