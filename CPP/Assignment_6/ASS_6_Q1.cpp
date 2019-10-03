/*
1. Read a string from user. The program should then calculate the frequency of occurrence of 
characters in the input string. It should store the results in a two dimentional array - 
first column is for the characters and 2nd column is for their frequency (you can use 2nd 
column of type char to store int, as we can safely assume that the frequency number would 
fit in one byte). It should then display the 2-column table of char-frequency.*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

inline int sizeofstr(char str[])
{
    return strlen(str);
}
void countFreuency(char str[],char cf[][1],int size)
{
    for(int i=0;i<size;i+=1)
        ++cf[tolower(str[i])-97][0];
}

int main()
{
    int slen=0;
    char str[50]={},freq[26][1]={}; // to store string from user
    cin.getline(str,50);
    slen=sizeofstr(str);
    countFreuency(str,freq,slen);
    
    cout<<"string \""<<str<<"\""<<" with character freuency:: \n";
    for(int i=0;i<26;++i)
        cout<<(char)(i+97)<<" : "<<(int)freq[i][0]<<"\n";

	return 0;
}