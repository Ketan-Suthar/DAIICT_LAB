/*
1. Write a program that declares array of 5 pointers to strings. That is, each element of this 5 element array is a char*. Allocate memory to read a maximum of 200 characters for each element of the array. Read 5 names from the user using these pointers. Display all names. Now, re-allocate memory to these pointers equal to the size of the names. Display the names again to verify it is correct allocation. Don't forget to free the pointers at end of the program.
*/
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main()
{
  char *names[5];
  for (int c = 0; c < 5; c++)
  {
      names[c] = new char[200];
	  cout<<"\nEnter name_"<<c+1;
	  cin.getline(names[c],200);
  }
  cout<<"\nnames before re-allocating memory: ";
  for (int c = 0; c < 5; c++)
  {
	cout<<"\nname_"<<c+1<<" :: "<<names[c];
  }
  cout<<"\nnames after re-allocating memory: ";
  for (int c = 0; c < 5; c++)
  {
      	names[c] = (char*) realloc(names[c], sizeof(strlen(names[c])));
	  cout<<"\nname_"<<c+1<<" :: "<<names[c];
  }
  delete names;
  return 0;
}
