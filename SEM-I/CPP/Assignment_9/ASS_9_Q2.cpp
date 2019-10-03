/*
2. Declare a structure Player. It has following member variables (properties):
name: a pointer to string that is name of the player
age: an integer to store name
game: a pointer to string that stores game of the player
The program should read string inputs from user in single pointer variable named input. This input variable is pointer whose memory is allocated on heap with size of 100 characters. After user given an input (eg. for name) the program copies this string to the field of the structure (eg. the name field). Make sure only required characters are copied.
Display the name, age and game of the player after reading the data. Make sure you de-allocate all memories allocated before program exits.
*/
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

struct player
{
	char *name;
	int age;
	char *game;
};

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
