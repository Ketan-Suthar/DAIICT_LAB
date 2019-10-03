/*
4. Write a function which is passed in set of pages. It returns the index of the page that has highest number of words in it. Use the function written in previous example to calculate number of words in each page.
*/

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int countWords(char page[5][100][100])
{
	int max=0,maxInd=0;
	for(int p=0;p<5;++p)
	{
		int words = 0;
		for(int j=0;j<100;++j)
		{
			int len = strlen(page[p][j]);
			for (int i = 0; i<len;++i) // iterate through every word
			{
				if (page[p][j][i] != ' ')//check leeter if not space
				{
					/* increament i till reach the end of word */
					while (((page[p][j][i] >= 65 && page[p][j][i] <= 90) || (page[p][j][i] >= 97 && page[p][j][i] <= 122)) && i<len)
						++i;
					++words;   // increament word by 1
				}
				/* increament i till consecutive space occures */
				while (page[p][j][i] == ' ' && i<len)
					++i;
			}
		}
		if(words>max)
		{
			max=words;
			maxInd = p+1;
		}
		cout << "\nwords on page " << p + 1 << " are:: " << words;
	}
	cout << "\npage " << maxInd<< " has highest number of pages";
}

int main()
{
	int words = 0;
	char pages[5][100][100] = {
		{"this is the first page","dedicated to my parents"," now","no"," thank you!"},
		{"this is the second page","dedicated to my mom and dad"," now third","no empty"," thank you!"},
		{"this is the third ","dedicated to my friends"," now third","no empty"," thank you!"},
		{"this is the forth","dedicated to no one"," now third","no empty"," thank you!"},
		{"this is last","dedicated to myself"," now third","no empty"," thank you!"},
		};
	
	countWords(pages);
	return 0;
}
