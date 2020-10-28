/**
 * 寻找map数组中的路径，-1表示墙，0表示控制的目标，1表示可以走的点,2表示终点
 * 显示出来就是#表示强，$表示控制的目标，空格表示可走路，*表示终点
 */
#include<iostream>
#include<stack>
#include<ctime>
#include<cstdlib>
#define H 20
#define W 20
struct LNode
{
	int x,y;
};
int map[H][W];
int fx[4]={-2,0,2,0},fy[4]={0,2,0,-2};
std::stack<LNode>s;
void init()
{
	for(int i = 0;i < H;i++)
	{
		if(i % 2 == 1)
		continue;
		for(int j = 0;j < W;j++)
		{
			if(j % 2 == 0)
			{
				map[i][j] = 1;
			}
		}
	}
}
bool judge(LNode a)
{
	int xx,yy;
	for(int i = 0;i < 4;i++)
	{
		xx = a.x + fx[i];
		yy = a.y + fy[i];
		if(xx>= 0 && xx < H && yy >= 0 && yy < W && map[xx][yy] == 1)
		{
			return false;
		}
	}
	s.pop();
	return true;
}
void show()
{
	for(int i = 0;i < H;i++)
	{
		for(int j = 0;j < W;j++)
		{
			if(map[i][j] == 0)
			{
				std::cout<<"#";
				map[i][j] = -1;
			}
			else if(map[i][j] == 1)
			{
				std::cout<<"$";
				map[i][j] = 0;
			}
			else if(map[i][j] == 2)
			{
				std::cout<<" ";
				map[i][j] = 1;
			}
			else if(map[i][j] == 3)
			{
				std::cout<<"*";
				map[i][j] = 2;
			}
		}
		std::cout<<std::endl;
	}
}
void refresh()
{
	LNode end;
	while(true)
	{
		if(s.empty())
		{
			break;
		}
		if(judge(s.top()))
		{
			continue;
		}
		LNode a = s.top();
		int xx,yy;
		LNode k;
		while(true)
		{
			xx = rand() % 4;
			k.x = a.x + fx[xx];
			k.y = a.y + fy[xx];
			if(k.x >= 0 && k.x < H && k.y >= 0 && k.y < W && map[k.x][k.y] == 1)
			{
				s.push(k);
				end = k;
				map[k.x][k.y] = 2;
				map[(k.x + a.x) / 2][(k.y + a.y) / 2] = 2;
				break;
			}
		}
	}
	map[end.x][end.y] = 3;
	map[0][0] = 1;
	show();
}
int main()
{
	srand((unsigned)time(NULL));
	init();
	LNode a;
	a.x = 0;
	a.y = 0;
	map[0][0] = 2;
	s.push(a);
	refresh();
	
	return 0;
}