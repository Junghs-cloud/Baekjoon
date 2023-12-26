#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <deque>
using namespace std;
set<long long> s;
vector<long long> v;
deque<long long> st;
int N;
vector<long long>::iterator it1;
set<long long>::iterator it2;

bool get(long long num)
{
	if (s.size() == N)
	{
		return true;
	}
	else
	{
		bool b1 = false;
		bool b2 = false;
		if (num % 3 == 0)
		{
			it1 = find(v.begin(), v.end(), num/3);
			it2 = find(s.begin(), s.end(), num / 3);
			if (it1 != v.end() && it2 == s.end())
			{
				s.insert(num / 3);
				st.push_back(num / 3);
				b1 = get(num / 3);
			}
		}
		it1 = find(v.begin(), v.end(), num * 2);
		it2 = find(s.begin(), s.end(), num * 2);
		if (it1 != v.end() && it2 == s.end())
		{
			s.insert(num * 2);
			st.push_back(num * 2);
			b2 = get(num * 2);
		}
		if (b1 == false && b2 == false)
		{
			s.erase(num);
			st.pop_back();
			return false;
		}
		else
		{
			return true;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	long long num;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	for (int i = 0; i < N; i++)
	{
		s.insert(v.at(i));
		st.push_back(v.at(i));
		if (get(v.at(i)) == true)
		{
			for (int i = 0; i < st.size(); i++)
			{
				cout << st.at(i) << " ";
			}
			break;
		}
		else
		{
			s.clear();
			while (!st.empty())
			{
				st.pop_back();
			}
		}
	}
	return 0;
}