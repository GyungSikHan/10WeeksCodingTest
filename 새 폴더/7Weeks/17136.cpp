#include <bits/stdc++.h>

using namespace std;

int ma[14][14], ret =987654321;
map<int, int> m;

bool check(int y, int x, int cnt)
{
	if(y+cnt > 10 || x +cnt > 10)
		return false;
	
	for(int i = y; i < y+cnt; i++)
	{
		for(int j = x; j < x+cnt; j++)
		{
			if(ma[i][j] == 0)
				return false;
		}
	}
	return true;
}
void draw(int y, int x, int cnt, int value)
{
	for(int i = y; i < y+cnt; i++)
	{
		for(int j =x; j < x+cnt; j++)
		{
			ma[i][j] = value;
		}
	}
}
void dfs(int y, int x, int cnt)
{
	if(cnt > ret)
		return;
	if(x == 10)
	{
		dfs(y+1, 0, cnt);
		return;
	}
	if(y == 10)
	{
		ret = min(cnt, ret);
		return;
	}

	if(ma[y][x] == 0)
	{
		dfs(y,x+1,cnt);
		return;
	}

	for(int i = 5; i >= 1; i--)
	{
		if(m[i] == 5)
			continue;
		if(check(y,x,i))
		{
			m[i]++;
			draw(y,x,i,0);
			dfs(y,x+i,cnt+1);
			draw(y,x,i,1);
			m[i]--;
		}
	}

	return ;
}

int main()
{
	for(int i =0; i < 10; i++)
	{
		for(int j =0; j < 10; j++)
		{
			cin>>ma[i][j];
		}
	}
	dfs(0,0,0);
	cout<<(ret == 987654321? -1 : ret);
}