#include <iostream>
using namespace std;
int N = 8;
int maze[8][8] = {
    {0,0,0,0,0,0,0,1},
    {0,1,1,0,1,1,0,1},
    {0,0,0,1,0,0,0,1},
    {0,1,0,0,1,1,0,0},
    {0,1,1,1,0,0,1,1},
    {0,1,0,0,0,1,0,1},
    {0,0,0,1,0,0,0,1},
    {0,1,1,1,0,1,0,0}};  

int pathway = 0;
int wall = 1;
int blocked = 2;
int visited = 3;

bool findMazePath(int x, int y)
{
	if(x < 0 || y < 0 || x >= N || y >= N)	 return false;
	else if(maze[x][y] != pathway)			 return false;
	else if(x == N - 1 && y == N - 1)		 return true;
	else
	{
		maze[x][y] = visited;
		if(findMazePath(x-1, y) || findMazePath(x+1, y) || findMazePath(x, y-1) || findMazePath(x, y+1))
		{
			return true;
		}
		maze[x][y] = blocked;
		return false;
	}
}

int main()
{
	string str = (findMazePath(0, 0))? "true" : "false";
	cout << str << endl;
	return 0;
}
