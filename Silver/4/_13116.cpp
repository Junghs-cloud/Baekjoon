#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T, A, B;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> A >> B;
		vector<int> va;
		vector<int> vb;
		while (A != 0)
		{
			va.push_back(A);
			A /= 2;
		}
		while (B != 0)
		{
			vb.push_back(B);
			B /= 2;
		}
		sort(vb.begin(), vb.end());
		for (int i = 0; i < va.size(); i++)
		{
			if (binary_search(vb.begin(), vb.end(), va.at(i)) == true)
			{
				cout << va.at(i) * 10 << "\n";
				break;
			}
		}
	}
	return 0;
}