/*
5. reverses the string and prints it.
*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main()
{
    char name[50]={};
    char dest[50]={};
    char *p=name;
    char *d=dest;
    int len;
    cin.getline(name,50);
    len = strlen(name);
    for(int i=0;i<len-1;++i)
        p++;
    while(p>=(&name[0]))
    {
        *d=*p;
        p--;
        d++;
    }
    cout<<"string \""<<name<<"\" in reverse order :: "<<dest;
	return 0;
}
