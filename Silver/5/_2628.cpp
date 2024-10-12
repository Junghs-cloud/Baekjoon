#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, K;
	int a, b;
	cin >> N >> M;
	cin >> K;
	vector<int> v0;
	vector<int> v1;
	vector<int> garo;
	vector<int> sero;
	v0.push_back(0);
	v0.push_back(M);
	v1.push_back(0);
	v1.push_back(N);
	for (int i = 0; i < K; i++)
	{
		cin >> a >> b;
		if (a == 0)
		{
			v0.push_back(b);
		}
		else
		{
			v1.push_back(b);
		}
	}
	sort(v0.begin(), v0.end());
	sort(v1.begin(), v1.end());
	for (int i = 1; i < v0.size(); i++)
	{
		garo.push_back(v0.at(i) - v0.at(i - 1));
	}
	for (int i = 1; i < v1.size(); i++)
	{
		sero.push_back(v1.at(i) - v1.at(i - 1));
	}
	sort(garo.begin(), garo.end());
	sort(sero.begin(), sero.end());
	cout << garo.back() * sero.back() << "\n";
	return 0;
}