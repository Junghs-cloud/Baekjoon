#include <iostream>
#include <map>
#include <set>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int A, B, C, N;
	string menu;
	int price;
	long long normalPrice = 0;
	long long specialPrice = 0;
	int serviceMenuCount = 0;
	cin >> A >> B >> C;
	map<string, int> normal;
	map<string, int> special;
	map<string, int>::iterator it;
	set<string> service;
	for (int i = 0; i < A; i++)
	{
		cin >> menu >> price;
		normal.insert({ menu, price });
	}
	for (int i = 0; i < B; i++)
	{
		cin >> menu >> price;
		special.insert({ menu, price });
	}
	for (int i = 0; i < C; i++)
	{
		cin >> menu;
		service.insert(menu);
	}
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> menu;
		it = normal.find(menu);
		if (it != normal.end())
		{
			normalPrice += it->second;
			continue;
		}
		it = special.find(menu);
		if (it != special.end())
		{
			specialPrice += it->second;
			continue;
		}
		serviceMenuCount++;
	}
	if (serviceMenuCount == 1)
	{
		if (specialPrice != 0 && normalPrice >= 20000 && specialPrice + normalPrice >= 50000)
		{
			cout << "Okay" << "\n";
		}
		else if (specialPrice == 0 && normalPrice >= 50000)
		{
			cout << "Okay" << "\n";
		}
		else
		{
			cout << "No" << "\n";
		}
	}
	else if (serviceMenuCount==0)
	{
		if (specialPrice != 0 && normalPrice >= 20000)
		{
			cout << "Okay" << "\n";
		}
		else if (specialPrice == 0)
		{
			cout << "Okay" << "\n";
		}
		else
		{
			cout << "No" << "\n";
		}
	}
	else
	{
		cout << "No" << "\n";
	}
	return 0;
}