/*
2. counts the number of capital letters in it.
*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main()
{
    int cnt=0; //to count number of capital letters
    string str; // to store string from user
    getline(cin,str);
    
    for(int i=0;i<str.size();++i)
    {
        int temp= str[i];
        if(temp>=65 && temp<=90)
            ++cnt;
    }        
    cout<<"\ncaptial letters in string \""<<str<<"\" are:: "<<cnt;
	return 0;
}
