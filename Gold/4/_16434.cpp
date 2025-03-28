#include <iostream>
using namespace std;
int N, H;
long long answer = 123456000000000001;

struct info
{
	long long type;
	long long a;
	long long h;
	info()
	{
		type = 0;
		a = 0;
		h = 0;
	}
};
info* rooms;

bool fight(long long maxHP)
{
	long long currentHP = maxHP;
	long long currentATK = H;
	for (int i = 0; i < N; i++)
	{
		if (rooms[i].type == 1)
		{
			long long monsterHP = rooms[i].h;
			long long monsterATK = rooms[i].a;
			long long personAttackCount = monsterHP / currentATK;
			if (monsterHP % currentATK != 0)
			{
				personAttackCount++;
			}
			currentHP -= monsterATK * (personAttackCount - 1);
			if (currentHP <= 0)
			{
				return false;
			}
		}
		else
		{
			currentATK += rooms[i].a;
			currentHP = min(currentHP + rooms[i].h, maxHP);
		}
	}
	return true;
}

void binarySearch(long long start, long long end)
{
	long long left = start;
	long long right = end;
	while (left <= right)
	{
		long long maxHP = (left + right) / 2;
		bool canClear = fight(maxHP);
		if (canClear == false)
		{
			left = maxHP + 1;
		}
		else
		{
			right = maxHP - 1;
			answer = min(answer, maxHP);
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> H;
	long long type, a, h;
	rooms = new info[N];
	for (int i = 0; i < N; i++)
	{
		cin >> type >> a >> h;
		rooms[i].type = type;
		rooms[i].a = a;
		rooms[i].h = h;
	}
	binarySearch(1, 123456000000000001);
	cout << answer << "\n";
	return 0;
}