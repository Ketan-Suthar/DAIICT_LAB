/*
2. Read a string from user. The program then should display
 the string with its charaters in alphabetic order.

*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

inline int sizeofstr(char str[])
{
    return strlen(str);
}
void sortSting(char str[],int size)
{
    int i,j;
    for (i = 0; i < size-1; i++)     
        for (j = 0; j < size-i-1; j++)  
            if (str[j] > str[j+1])  
                {
                    char t= str[j];
                    str[j]=str[j+1];
                    str[j+1]=t;
                }
}

int main()
{
    int slen=0;
    char str[50]={}; // to store string from user
    cin.getline(str,50);
    slen=sizeofstr(str);
    cout<<"String before sorting:: \""<<str<<"\"";
    sortSting(str,slen);
    cout<<"\nString after sorting:: \""<<str<<"\"";

	return 0;
}