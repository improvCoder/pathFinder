// pathFinder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;


int move(int array[][5], int x, int y, int temp[][5])
{
	if (temp[x][y] == 0)
	{
		move(array, x + 1, y, temp);
	}
	if (array[x][y] == 0 and temp[x][y] != 0)
	{
		temp[x][y] = 0;
		move(array, x, y - 1, temp);
		move(array, x, y + 1, temp);
		move(array, x-1, y, temp);
		move(array, x+1, y, temp);
	}
	if (array[x][y] == 1)
	{
		if (array[x][y - 1] == 0)
		{
			move(array, x, y - 1, temp);
		}
	}
	return 0;
}


void print(int array[][5])
{

	for (int a = 0; a < 5; a++)
	{
		for (int b =0; b < 5; b++)
		{
			cout<<array[a][b]<<" ";
		}
		cout << endl;
	}
}

int main()
{
	int temp[11][5];
	
	
	int array[11][5] = { {0,0,1,1,1},{1,0,0,0,1},{1,1,1,0,1},{1,1,1,0,0},{0,0,0,1,0},{0,1,0,0,0},{0,0,1,1,1},{1,0,1,1,1},{1,0,0,1,1},{1,1,0,1,1},{1,1,0,0,0} };
	for (int a = 0; a < 11; a++)
	{
		for (int b =0; b < 5; b++)
		{
			temp[a][b] = 3;
		}
	}
	cout << "Input Matrix" << endl;
	print(array);

	cout << "Before the Call" << endl;
	print(temp);

	move(array, 0, 0, temp);

	cout << "The path Matrix" << endl;
	print(temp);

}