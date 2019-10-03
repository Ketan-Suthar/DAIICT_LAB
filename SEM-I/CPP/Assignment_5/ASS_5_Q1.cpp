/*
1. counts the number of vowels in it.
*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main()
{
    int cnt=0; //to count number of vowels
    string str; // to store string from user
    getline(cin,str);
    
    for(int i=0;i<str.size();++i)
    {
        char temp= tolower(str[i]);
        if(temp=='a' || temp=='e' || temp=='i' || temp=='o' || temp=='u')
            ++cnt;
    }        
    cout<<"\nvowels in string \""<<str<<"\" are:: "<<cnt;
	return 0;
}
