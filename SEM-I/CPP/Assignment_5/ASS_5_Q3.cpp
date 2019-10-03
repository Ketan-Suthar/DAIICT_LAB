/*
3. converts the string to all capital letters.
*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main()
{
    
    string str; // to store string from user
    getline(cin,str);
    string upper=str;
    for(int i=0;i<upper.size();++i)
    {
        int temp= str[i];
        if(temp>=97 && temp<=122)
            upper[i] = upper[i]-32;
    }        
    cout<<"\nstring \""<<str<<"\" in capital is:: "<<upper;
	return 0;
}
