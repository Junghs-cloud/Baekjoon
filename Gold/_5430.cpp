#include <iostream>
#include <deque>
#include <sstream>
using namespace std;

int main()
{
	deque<int> dq;
	int T;
	string p;
	int n;
	string arrStr;
	string token;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int isForward = 0;
		bool flag = true;
		cin >> p;
		cin >> n;
		cin >> arrStr;
		if (arrStr.length() != 2)
		{
			arrStr = arrStr.substr(1, arrStr.length() - 2);
		}
		else
		{
			arrStr = "";
		}
		istringstream ss(arrStr);
		while (getline(ss, token, ','))
		{
			int num = stoi(token);
			dq.push_back(num);
		}
		for (int j = 0; j < (signed) p.length(); j++)
		{
			if (p[j] == 'R')
			{
				isForward++;
			}
			else
			{
				if (!dq.empty())
				{
					if (isForward % 2 == 1)
					{
						dq.pop_back();
					}
					else
					{
						dq.pop_front();
					}
				}
				else
				{
					cout << "error"<<"\n";
					flag = false;
					break;
				}
			}
		}
		if (flag == true)
		{
			cout << "[";
			if (!dq.empty())
			{
				if (isForward % 2 == 0)
				{
					for (int i = 0; i < dq.size(); i++)
					{
						if (i != dq.size() - 1)
						{
							cout << dq[i] << ",";
						}
						else
						{
							cout << dq[i];
						}
					}
				}
				else
				{
					for (int i = dq.size()-1; i >= 0; i--)
					{
						if (i != 0)
						{
							cout << dq[i] << ",";
						}
						else
						{
							cout << dq[i];
						}
					}
				}
			}
			cout << "]\n";
		}
		dq.clear();
	}
	return 0;
}