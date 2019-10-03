/*
4. counts the number of words in it.
*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main()
{
    int words=0;
    string str; // to store string from user
    getline(cin,str);
    
    for(int i=0;i<str.size();) // iterate through every word
    {
        if(str[i]!=' ')//check leeter if not space
        {
            /* increament i till reach the end of word */
            while(((str[i]>=65 && str[i]<=90) || (str[i]>=97 && str[i]<=122)) && i<str.size())
                ++i;
            ++words;   // increament word by 1
        }
        /* increament i till consecutive space occures */
        while(str[i]==' ' && i<str.size())
                ++i;
    }        
    cout<<"words in string \""<<str<<"\" are:: "<<words;
	return 0;
}
