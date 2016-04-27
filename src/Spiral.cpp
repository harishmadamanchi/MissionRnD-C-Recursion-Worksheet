/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>

void get_spiralarray(int **input_array, int rows, int columns, int rowsnum, int columnsnum, int *index, int *resultarray);

int *spiral(int rows, int columns, int **input_array)
{
	if (input_array == NULL)
		return NULL;
	int *resultarray, columnsnum = 0, rowsnum = 0, index = 0;
	resultarray = (int*)malloc(sizeof(int));
	get_spiralarray((int**)input_array, rows, columns, rowsnum, columnsnum, &index,resultarray);
	return resultarray;
}

void get_spiralarray(int **input_array, int rows, int columns, int rowsnum, int columnsnum, int *index,int *resultarray){
	int i;
	if (rowsnum < rows && columnsnum < columns){
		for (i = columnsnum; i < columns; i++){
			resultarray[*index] = input_array[rowsnum][i];
			*index = *index + 1;
		}
		rowsnum++;
		for (i = rowsnum; i < rows; i++){
			resultarray[*index] = input_array[i][columns - 1];
			*index = *index + 1;
		}
		columns--;
		if (rowsnum < rows){
			for (i = columns - 1; i >= 1; i--){
				resultarray[*index] = input_array[rows - 1][i];
				*index = *index + 1;
			}
			rows--;
		}
		if (columnsnum < columns){
			for (i = rows - 1; i >= rowsnum; i--){
				resultarray[*index] = input_array[i][columnsnum];
				*index = *index + 1;
			}
			columnsnum++;
		}
		get_spiralarray((int**)input_array, rows, columns, rowsnum, columnsnum, index, resultarray);
	}
}
