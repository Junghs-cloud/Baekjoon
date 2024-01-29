#include <iostream>
using namespace std;

int main()
{
	int H, W, N, M;
	int answer = 0;
	cin >> H >> W >> N >> M;
	for (int i = 0; i < H; i+=(N+1))
	{
		for (int j = 0; j < W; j+=(M+1))
		{
			answer++;
		}
	}
	cout << answer << "\n";
	return 0;
}