#include <iostream>
#include <map>
using namespace std;

long long* arr;
map<long long, long long> m;
map<long long, long long>::iterator it;

long long calc(long long x)
{
	long long a = 0;
	long long b = 0;
	long long F1 = 0;
	long long F2 = 0;
	it = m.find(x);
	if (it!=m.end())
	{
		return it->second;
	}
	else
	{
		if (x % 2 == 0)
		{
			b = x / 2;
			a = b - 1;
			F1 = x / 2;
			F2 = F1 + 1;
		}
		else
		{
			b = (x + 1) / 2;
			a = b - 1;
			F1 = x / 2;
			F2 = F1 + 1;
		}
		long long answer = calc(a)% 1000000007* calc(F1) % 1000000007 + calc(b) % 1000000007 * calc(F2) % 1000000007;
		m.insert({ x, answer });
		return answer % 1000000007;
	}
}

int main()
{
	long long N;
	cin >> N;
	arr = new long long[11];
	arr[0] = 0;
	m.insert({ 0, 0 });
	arr[1] = 1;
	m.insert({ 1, 1 });
	for (int i = 2; i < 11; i++)
	{
		arr[i] = arr[i - 2] + arr[i - 1];
		m.insert({ i, arr[i] });
	}
	cout<<calc(N)<<"\n";
	return 0;
}