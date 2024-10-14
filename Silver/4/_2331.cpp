#include <iostream>
#include <string>
#include <map>
using namespace std;

int pow(int N, int P)
{
	int temp = N;
	for (int i = 1; i < P; i++)
	{
		temp = temp * N;
	}
	return temp;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string N;
	int P;
	int index = 1;
	cin >> N >> P;
	map<string, int> m;
	map<string, int>::iterator it;
	m.insert({ N, index });
	while (true)
	{
		int num = 0;
		for (int i = 0; i < N.length(); i++)
		{
			num += pow(N[i]-48, P);
		}
		N = to_string(num);
		index++;
		it = m.find(N);
		if (it == m.end())
		{
			m.insert({N, index});
		}
		else
		{
			cout << it->second - 1 << "\n";
			break;
		}
	}
	return 0;
}