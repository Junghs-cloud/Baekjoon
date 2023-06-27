#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct lecture
{
	int a;
	int b;
	int c;
	lecture(int x, int y, int z)
	{
		a = x;
		b = y;
		c = z;
	}
};

bool compareAB(const lecture& l1, const lecture& l2)
{
	if (l1.a + l1.b > l2.a + l2.b)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool compareAC(const lecture& l1, const lecture& l2)
{
	if (l1.a + l1.c > l2.a + l2.c)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool compareBC(const lecture& l1, const lecture& l2)
{
	if (l1.b + l1.c > l2.b + l2.c)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K;
	int a, b, c;
	long long sum = 0;
	long long sumCheck= 0;
	vector<lecture> v;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b >> c;
		v.push_back(lecture(a, b, c));
	}
	sort(v.begin(), v.end(), compareAB);
	for (int i = 0; i < K; i++)
	{
		sumCheck += ((long long)v.at(i).a+(long long)v.at(i).b);
	}
	if (sum < sumCheck)
	{
		sum = sumCheck;
	}
	sumCheck = 0;
	sort(v.begin(), v.end(), compareAC);
	for (int i = 0; i < K; i++)
	{
		sumCheck += ((long long)v.at(i).a + (long long)v.at(i).c);
	}
	if (sum < sumCheck)
	{
		sum = sumCheck;
	}
	sumCheck = 0;
	sort(v.begin(), v.end(), compareBC);
	for (int i = 0; i < K; i++)
	{
		sumCheck += ((long long)v.at(i).b + (long long)v.at(i).c);
	}
	if (sum < sumCheck)
	{
		sum = sumCheck;
	}
	sumCheck = 0;
	cout << sum << "\n";
	return 0;
}