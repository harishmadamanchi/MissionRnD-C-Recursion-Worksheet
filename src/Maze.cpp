/*
Find if there is a connecting path between two given points in the maze.
The maze is a matrix of order MxN, check if there exists a path between (x1,y1) and (x2,y2).
Two points are said to connected if there is a series of 1's non-diagonally.
Example:
Maze of order 4x4:

1	0	1	0
1	1	0	0
0	1	0	1
0	1	1	1

(x1,y1):(0,0)
(x2,y2):(2,3)

In this case, there exists a connected path:
1
1	1
	1		1
	1	1	1

Since there is a connected path, your function has to return 1.
If a path doesn't exist between two co-ordinates then return 0.
If the co-ordinates are invalid or size of the matrix is invalid then return 0.

Function Prototype :path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2) ;
Maze: Pointer to first element of an array .
rows : No of rows
columns : Columns
x1,x2,y1,y2: Co-ordinates

Hint : You can use path_exists as a wrapper function for your original recursive function which might take
more parameters .
*/

#include<stdlib.h>

int is_exist(int *, int, int, int, int);

int path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2)
{
	int res1, res2;
	if (x1 < rows&&y1 < columns&&x1 >= 0 && y1 >= 0 && x2<rows&&y2<columns&&x2 >= 0 && y2 >= 0 && *((maze + x1*columns) + y1) == 1 && *((maze + x2*columns) + y2) == 1){

		res1 = is_exist(maze, x1 + 1, y1, rows, columns);
		res2 = is_exist(maze, x1, y1 + 1, rows, columns);
		if (res1 == 1){
			x1 = x1 + 1;
			y1 = y1;
		}
		else if (res2 == 1){
			x1 = x1;
			y1 = y1 + 1;
		}
		else
			return 0;
		if (x1 == x2&&y1 == y2){
			return 1;
		}
		else
			path_exists(maze, rows, columns, x1, y1, x2, y2);
	}
	else
		return 0;
}

int is_exist(int *maze, int x, int y, int rows, int columns){
	if (*((maze + x*columns) + y) == 1 && x<rows&&y<columns)
		return 1;
	else
		return 0;
}