#include <iostream>
#include <map>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	string child;
	string parent;
	string find1, find2;
	bool isFind = false;
	cin >> N;
	map<string, string> m;
	map<string, string>::iterator it;
	for (int i = 0; i < N-1; i++)
	{
		cin >> child >> parent;
		m.insert({child, parent});
	}
	cin >> find1 >> find2;
	it = m.find(find1);
	while (it != m.end())
	{
		if (it->second == find2)
		{
			isFind = true;
			break;
		}
		it = m.find(it->second);
	}
	if (isFind == false)
	{
		it = m.find(find2);
		while (it != m.end())
		{
			if (it->second == find1)
			{
				isFind = true;
				break;
			}
			it = m.find(it->second);
		}
	}
	if (isFind == false)
	{
		cout << "0" << "\n";
	}
	else
	{
		cout << "1" << "\n";
	}
	return 0;
}