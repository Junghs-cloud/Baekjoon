#include <iostream>
#include <stack>
using namespace std;

bool get(string A, string B)
{
	if (A.length() == B.length())
	{
		if (A == B)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		bool b1 = false;
		bool b2 = false;
		if (B[B.length() - 1] == 'A')
		{
			string str = B.substr(0, B.length() - 1);
			b1 = get(A, str);
		}
		if (B[0] == 'B')
		{
			stack<char> s;
			string str = "";
			for (int i = 1; i < B.length(); i++)
			{
				s.push(B[i]);
			}
			while (!s.empty())
			{
				str += s.top();
				s.pop();
			}
			b2 = get(A, str);
		}
		return (b1 || b2);
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string A, B;
	cin >> A >> B;
	cout<<get(A, B)<<"\n";
	return 0;
}