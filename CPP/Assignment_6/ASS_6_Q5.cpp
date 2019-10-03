/*
5. Create a two dimensional square array decor[MAX][MAX]. 
Fill this array up with two types of charaters, '-' and '*'. T
he fill should be such that when this array is displayed as a grid, 
following pattern is seen:
Outermost boder of the box/table is filled of '-' characters. 
Then the inner border is filled of '*' charaters. Then the next inner border of '-' 
and so on till no inner border is left to be filled. Take MAX as 11 to begin with.
 For MAX as 11, it should look like:
0  -----------
1  -*********-
2  -*-------*-
3  -*-*****-*-
4  -*-*---*-*-
5  -*-*-*-*-*-
6  -*-*---*-*-
7  -*-*****-*-
8  -*-------*-
9  -*********-
10 -----------

*/

#include <iostream>
#include <cstring>
#include <string>
#include <stdlib.h> 

using namespace std;
#define max(a, b) ((a > b) ? a : b)

#define MAX 13
int grid[MAX][MAX];

void printGrid(void)
{
	int len = (MAX/2)+1;
	for(int i = -len+1; i < len; i++)
    {
        for(int k = -len+1; k < len; k++)
        {
            int num = max(abs(i),abs(k))+1;
            if((num)%2==0)
            	cout<<"-";
           	else
           		cout<<"*";
        }
        printf("\n");
    }
	
}

int main(int argc, char const *argv[])
{
	printGrid();
	return 0;
}