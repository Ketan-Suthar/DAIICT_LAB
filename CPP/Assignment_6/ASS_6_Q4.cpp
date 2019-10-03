/*
4. There is a treasure that can be opened by a specific combination of three integers.
These three integers are to be selected from numbers stored in a 3-d array,
secrets[PAGES][ROWS][COLS] (take PAGES=ROWS=COLS=3).
The owner of this treasure knows a number whose individual digits are indices
 of numbers to be picked up from 1st, 2nd and 3rd page of the secrets array. 
 Eg. if the number is 259, it means pick the 2nd number from page 1, 
 5th from page 2 and 9th from page 3. 
Write a program that first fills up secrets array using numbers input by user. 
Then it takes the number from owner of treasure and displays the secret combination
 of 3 numbers.


*/

#include <iostream>
#include <cstring>
#include <string>
#include <stdlib.h> 

using namespace std;

#define PAGES 3
#define ROWS 3
#define COLS 3
int secrets[PAGES][ROWS][COLS];

void initializeSecrets(void)
{
	for(int i=0;i<PAGES;++i)
		for(int j=0;j<ROWS;++j)
			for(int k=0;k<COLS;++k)
				secrets[i][j][k]=rand();

}
void allSecrets(void)
{
	for(int i=0;i<PAGES;++i)
	{
		for(int j=0;j<ROWS;++j)
		
			for(int k=0;k<COLS;++k)
				cout<<secrets[i][j][k]<<" - ";;
		cout<<"\n";		
	}
}
void findSecret(int num)
{
	int p,c,r;
	c=num%10;
	num/=10;
	r=num%10;
	num/=10;
	p=num%10;
	num/=10;

	//cout<<"p: "<<p<<"r: "<<r<<"c: "<<c;
	cout<<"\nyour secret message is:: ";
	cout<<secrets[0][(p-1)/3][(p-1)%3]<<secrets[1][(r-1)/3][(r-1)%3]<<secrets[2][(c-1)/3][(c-1)%3];
}
int main(int argc, char const *argv[])
{
	int num;
	initializeSecrets();
	cout<<"\nwelcome treasure!!";
	cout<<"\ngive me three digit number and i will tell you the secret:: ";
	cin>>num;

	//allSecrets();
	findSecret(num);

	return 0;
}


