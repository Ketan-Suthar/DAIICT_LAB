/*
3. Read five strings from user. Find the longest string among the strings
 input and display it along with its length.


*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

inline int sizeofstr(char str[])
{
    return strlen(str);
}
int longestString(char s[][50])
{
    int max=0;
    for(int i=0;i<5;++i)
        if(sizeofstr(s[max])<sizeofstr(s[i]))
            max=i;
    return max;    
}
int main()
{
    int longest;
    char str[5][50]={}; // to store string from user
    for(int i=0;i<5;++i)
        cin.getline(str[i],50);
    
    cout<<"5 String are:: \n";
    for(int i=0;i<5;++i)
        cout<<i+1<<"th String:: \""<<str[i]<<"\"\n";
    longest=longestString(str);
    cout<<"\nLongest String is:: \""<<str[longest]<<"\"";

	return 0;
}